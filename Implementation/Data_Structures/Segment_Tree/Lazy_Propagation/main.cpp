/*******************************
Segment Tree: sum queries
Range update and point queries (Lazy Propagation)
*******************************/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node
{
    bool lazy = false;
    int sum = 0, lazyv = 0;
    Node() {}
};

struct LazySegment
{
    int n;
    vector<Node> t;

    LazySegment() {}
    LazySegment(vector<int> v)
    {
        int _n = v.size();
        for(n = 1; n < _n; n <<= 1);
        t.resize(2*n);
        for(int i = 0; i < _n; i++) t[i+n].sum = v[i];
        for(int i = n-1; i > 0; i--) t[i].sum = t[2*i].sum + t[2*i+1].sum;
    }

    void propaga(int i, int tl, int tr)
    {
        if(t[i].lazy)
        {
            t[i].sum += (t[i].lazyv * (tr - tl + 1));
            if(tl != tr)
            {
                t[2*i].lazy = t[2*i+1].lazy = true;
                t[2*i].lazyv += t[i].lazyv;
                t[2*i+1].lazyv += t[i].lazyv;
            }
            t[i].lazy = false;
            t[i].lazyv = 0;
        }
    }

    void update(int i, int tl, int tr, int l, int r, int x)
    {
        propaga(i, tl, tr);
        if(tr < l || r < tl) return;
        if(l <= tl && tr <= r)
        {
            t[i].lazy = true;
            t[i].lazyv += x;
        } else
        {
            int tm = (tl + tr) / 2;
            update(2*i, tl, tm, l, r, x);
            update(2*i+1, tm+1, tr, l, r, x);
            t[i].sum = t[2*i].sum + t[2*i+1].sum;
        }
    }

    void update(int l, int r, int x)
    {
        update(1, 0, n-1, l, r, x);
    }

    int query(int i, int tl, int tr, int p)
    {
        propaga(i, tl, tr);
        if(p < tl || tr < p) return 0;
        if(tl == tr && tr == p) return t[i].sum;
        int tm = (tl + tr) / 2;
        return query(2*i, tl, tm, p) + query(2*i+1, tm+1, tr, p);
    }

    int query(int p)
    {
        return query(1, 0, n-1, p);
    }
};

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for(int &i: v) cin >> i;

    LazySegment seg = LazySegment(v);

    int q; cin >> q;
    while(q--)
    {
        int type; cin >> type;
        if(type == 0) // update
        {
            int l, r, x; cin >> l >> r >> x;
            seg.update(l, r, x);
        } else // query
        {
            int p; cin >> p;
            cout << seg.query(p) << "\n";
        }
    }
}
