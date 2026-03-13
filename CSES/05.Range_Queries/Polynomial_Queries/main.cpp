#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegmentTree {
    int n;
    vector<ll> t, lazy, lazy2;

    SegmentTree(vector<int> &a) {
        n = a.size();
        t.resize(4 * n);
        lazy.resize(4 * n);
        lazy2.resize(4 * n);
        build(a, 1, 0, n - 1);
    }

    void build(vector<int> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, 2 * v, tl, tm);        // Corretto: Passiamo `a` come primo argomento
            build(a, 2 * v + 1, tm + 1, tr); // Corretto: Passiamo `a` come primo argomento
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }

    void push(int v, int tl, int tr) {
        if (lazy[v] != 0 || lazy2[v] != 0) {
            int tm = (tl + tr) / 2;
            apply(v * 2, tl, tm, lazy[v], lazy2[v]);
            apply(v * 2 + 1, tm + 1, tr, lazy[v] + lazy2[v] * (tm - tl + 1), lazy2[v]);
            lazy[v] = 0;
            lazy2[v] = 0;
        }
    }

    void apply(int v, int tl, int tr, ll add, ll add2) {
        t[v] += add * (tr - tl + 1) + add2 * (tr - tl) * (tr - tl + 1) / 2;
        lazy[v] += add;
        lazy2[v] += add2;
    }

    void update(int v, int tl, int tr, int l, int r, ll add, ll add2) {
        if (l > r) return;
        if (l == tl && r == tr) {
            apply(v, tl, tr, add, add2);
        } else {
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            update(2 * v, tl, tm, l, min(r, tm), add, add2);
            update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, add + add2 * max(0, tm - l + 1), add2);
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }

    ll query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l <= tl && tr <= r) {
            return t[v];
        }
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return query(2 * v, tl, tm, l, min(r, tm)) + query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    void update(int l, int r) {
        update(1, 0, n - 1, l, r, 1, 1);
    }

    ll query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    SegmentTree st(a);

    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        --l, --r;
        if (type == 1) {
            st.update(l, r);
        } else {
            cout << st.query(l, r) << "\n";
        }
    }

    return 0;
}

