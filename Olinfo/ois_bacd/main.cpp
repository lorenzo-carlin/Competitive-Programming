#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Segment
{
    int n;
    vector<ll> t;

    Segment() {}
    Segment(int _n)
    {
        for(n = 1; n < _n; n <<= 1);
        t.resize(2*n, 0);
    }

    void update(int i, int tl, int tr, int p, ll v)
    {
        if(p < tl || tr < p) return;
        if(tl == tr && tl == p) t[i] = v;
        else
        {
            int tm = (tl + tr) / 2;
            update(2*i, tl, tm, p, v);
            update(2*i+1, tm+1, tr, p, v);
            t[i] = t[2*i] + t[2*i+1];
        }
    }

    void update(int p, ll v)
    {
        update(1, 0, n-1, p, v);
    }

    ll query(int i, int tl, int tr, int l, int r)
    {
        if(r < tl || tr < l) return 0;
        if(l <= tl && tr <= r) return t[i];
        int tm = (tl + tr) / 2;
        return query(2*i, tl, tm, l, r) + query(2*i+1, tm+1, tr, l, r);
    }

    ll query(int l, int r)
    {
        return query(1, 0, n-1, l, r);
    }

    void print()
    {
        for(int i = n; i < 2*n; i++)
            cout << t[i] << " ";
        cout << "\n";
    }
};

struct SegTree
{
    struct nodo
    {
        ll val = 0;
        ll lazy = 0;
        int accesi = 0;
    };

    nodo merge(nodo a, nodo b)
    {
        nodo c;
        c.val = a.val + b.val;
        c.accesi = a.accesi + b.accesi;
        return c;
    }

    int n;
    vector<nodo> t;

    SegTree() {}
    SegTree(int _n)
    {
        for(n = 1; n < _n; n <<= 1);
        t.resize(2*n, nodo());
    }

    void propaga(int i, int tl, int tr)
    {
        if(t[i].lazy != 0)
        {
            if(t[i].accesi > 0)
                t[i].val += t[i].lazy * t[i].accesi;

            if(tl != tr)
            {
                t[2*i].lazy += t[i].lazy;
                t[2*i+1].lazy += t[i].lazy;
            }

            t[i].lazy = 0;
        }
    }

    void update(int i, int tl, int tr, int l, int r, ll delta)
    {
        propaga(i, tl, tr);
        if(r < tl || tr < l) return;
        if(l <= tl && tr <= r)
        {
            t[i].lazy += delta;
            propaga(i, tl, tr);
        } else
        {
            int tm = (tl + tr) / 2;
            update(2*i, tl, tm, l, r, delta);
            update(2*i+1, tm+1, tr, l, r, delta);
            t[i] = merge(t[2*i], t[2*i+1]);
        }
    }

    void update(int l, int r, ll delta)
    {
        update(1, 0, n-1, l, r, delta);
    }

    void add(int i, int tl, int tr, int p, ll v)
    {
        propaga(i, tl, tr);
        if(p < tl || tr < p) return;
        if(tl == tr && tl == p)
        {
            t[i].val = v;
            t[i].accesi = 1;
        } else
        {
            int tm = (tl + tr) / 2;
            add(2*i, tl, tm, p, v);
            add(2*i+1, tm+1, tr, p, v);
            t[i] = merge(t[2*i], t[2*i+1]);
        }
    }

    void add(int p, ll v)
    {
        add(1, 0, n-1, p, v);
    }

    ll query(int i, int tl, int tr, int l, int r)
    {
        propaga(i, tl, tr);
        if(r < tl || tr < l) return 0;
        if(l <= tl && tr <= r) return t[i].val;
        int tm = (tl + tr) / 2;
        return query(2*i, tl, tm, l, r) + query(2*i+1, tm+1, tr, l, r);
    }

    ll query(int l, int r)
    {
        return query(1, 0, n-1, l, r);
    }

    void print()
    {
        for(int i = 0; i < n; i++)
            update(i, i, 0);
        for(int i = n; i < 2*n; i++)
            cout << t[i].val << " ";
        cout << "\n";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> v(n);
    for(int &i: v) cin >> i;

    Segment seg1 = Segment(n+1);
    vector<int> dp2(n, 0);
    for(int i = n-1; i >= 0; i--)
    {
        dp2[i] = seg1.query(v[i], n);
        seg1.update(v[i], 1);
    }

    Segment B = Segment(n+1);
    for(int i = 0; i < n; i++)
        B.update(v[i], dp2[i]);

    SegTree A = SegTree(n+1);
    ll tot = 0;
    for(int i = 0; i < n; i++)
    {
        int x = v[i];
        B.update(x, 0);
        A.update(0, x-1, -dp2[i]);
        ll delta = B.query(x+1, n);
        A.add(x, delta);
        tot += A.query(x+1, n);
    }

    cout << tot << "\n";
}
