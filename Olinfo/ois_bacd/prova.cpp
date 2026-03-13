#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* ===================== SEGMENT TREE BASE ===================== */

struct Segment {
    int n;
    vector<ll> t;

    Segment(int _n = 0) {
        for(n = 1; n < _n; n <<= 1);
        t.assign(2*n, 0);
    }

    void update(int i, int tl, int tr, int p, ll v) {
        if(p < tl || tr < p) return;
        if(tl == tr) {
            t[i] = v;
            return;
        }
        int tm = (tl + tr) / 2;
        update(2*i, tl, tm, p, v);
        update(2*i+1, tm+1, tr, p, v);
        t[i] = t[2*i] + t[2*i+1];
    }

    void update(int p, ll v) {
        update(1, 0, n-1, p, v);
    }

    ll query(int i, int tl, int tr, int l, int r) {
        if(r < tl || tr < l) return 0;
        if(l <= tl && tr <= r) return t[i];
        int tm = (tl + tr) / 2;
        return query(2*i, tl, tm, l, r) +
               query(2*i+1, tm+1, tr, l, r);
    }

    ll query(int l, int r) {
        if(l > r) return 0;
        return query(1, 0, n-1, l, r);
    }
};

/* ===================== SEGMENT TREE A (CORRETTA) ===================== */

struct SegTreeA {
    int n;
    vector<ll> t, lazy;

    SegTreeA(int _n = 0) {
        for(n = 1; n < _n; n <<= 1);
        t.assign(2*n, 0);
        lazy.assign(2*n, 0);
    }

    void push(int i, int tl, int tr) {
        if(lazy[i] != 0) {
            t[i] += lazy[i] * (tr - tl + 1);
            if(tl != tr) {
                lazy[2*i] += lazy[i];
                lazy[2*i+1] += lazy[i];
            }
            lazy[i] = 0;
        }
    }

    void range_add(int i, int tl, int tr, int l, int r, ll v) {
        push(i, tl, tr);
        if(r < tl || tr < l) return;
        if(l <= tl && tr <= r) {
            lazy[i] += v;
            push(i, tl, tr);
            return;
        }
        int tm = (tl + tr) / 2;
        range_add(2*i, tl, tm, l, r, v);
        range_add(2*i+1, tm+1, tr, l, r, v);
        t[i] = t[2*i] + t[2*i+1];
    }

    void range_add(int l, int r, ll v) {
        if(l <= r) range_add(1, 0, n-1, l, r, v);
    }

    void point_set(int i, int tl, int tr, int p, ll v) {
        push(i, tl, tr);
        if(tl == tr) {
            t[i] = v;
            return;
        }
        int tm = (tl + tr) / 2;
        if(p <= tm) point_set(2*i, tl, tm, p, v);
        else point_set(2*i+1, tm+1, tr, p, v);
        t[i] = t[2*i] + t[2*i+1];
    }

    void point_set(int p, ll v) {
        point_set(1, 0, n-1, p, v);
    }

    ll query(int i, int tl, int tr, int l, int r) {
        push(i, tl, tr);
        if(r < tl || tr < l) return 0;
        if(l <= tl && tr <= r) return t[i];
        int tm = (tl + tr) / 2;
        return query(2*i, tl, tm, l, r) +
               query(2*i+1, tm+1, tr, l, r);
    }

    ll query(int l, int r) {
        if(l > r) return 0;
        return query(1, 0, n-1, l, r);
    }
};

/* ===================== MAIN ===================== */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int &x : v) cin >> x;

    /* ---- dp2 ---- */
    Segment seg1(n+1);
    vector<int> dp2(n, 0);

    for(int i = n-1; i >= 0; i--) {
        dp2[i] = seg1.query(v[i], n);
        seg1.update(v[i], 1);
    }

    /* ---- B ---- */
    Segment B(n+1);
    for(int i = 0; i < n; i++)
        B.update(v[i], dp2[i]);

    /* ---- A ---- */
    SegTreeA A(n+1);

    /* ---- algoritmo ---- */
    ll tot = 0;
    for(int i = 0; i < n; i++) {
        int x = v[i];

        B.update(x, 0);

        ll delta = B.query(x+1, n);
        A.point_set(x, delta);

        A.range_add(0, x-1, -dp2[i]);

        tot += A.query(x+1, n);
    }

    cout << tot << "\n";
    return 0;
}

