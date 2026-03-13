#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node
{
    ll sum = 0;
    ll lazy = 0;
};

struct Segment
{
    vector<node> t;
    int n;

    Segment(int _n, vector<ll> a)
    {
        for(n = 1; n < _n; n <<= 1);
        t.resize(2*n);
        for(int i = 0; i < _n; ++i) t[i+n].sum = a[i];
        for(int i = n-1; i >= 0; --i) t[i].sum = t[2*i].sum + t[2*i+1].sum;
    }

    void propaga(int i, int tl, int tr)
    {
        t[i].sum += t[i].lazy * (tr - tl + 1);
        if(tl != tr)
        {
            t[2*i].lazy += t[i].lazy;
            t[2*i+1].lazy += t[i].lazy;
        }
        t[i].lazy = 0;
    }

    void update(int i, int tl, int tr, int l, int r, int x)
    {
        propaga(i, tl, tr);
        if(r < tl || tr < l) return;
        if(l <= tl && tr <= r)
        {
            t[i].lazy += x;
            propaga(i, tl, tr);
            return;
        }
        int tm = (tl + tr) / 2;
        update(2*i, tl, tm, l, r, x);
        update(2*i+1, tm+1, tr, l, r, x);
        t[i].sum = t[2*i].sum + t[2*i+1].sum;
    }

    void update(int l, int r, int x)
    {
        update(1, 0, n-1, l, r, x);
    }

    ll query(int i, int tl, int tr, int l, int r)
    {
        propaga(i, tl, tr);
        if(r < tl || tr < l) return 0;
        if(l <= tl && tr <= r) return t[i].sum;
        int tm = (tl + tr) / 2;
        return query(2*i, tl, tm, l, r) + query(2*i+1, tm+1, tr, l, r);
    }

    ll query(int l, int r)
    {
        return query(1, 0, n-1, l, r);
    }
};


int main()
{
    int n, q; cin >> n >> q;
    vector<ll> a(n);
    for(auto &el: a) cin >> el;
    Segment st = Segment(n, a);
    for(int i = 0; i < q; ++i)
    {
        int c; cin >> c;
        if(c == 1)
        {
            int l, r, x; cin >> l >> r >> x; l--; r--;
            st.update(l, r, x);
        } else
        {
            int k; cin >> k; k--;
            cout << st.query(k, k) << "\n";
        }
    }
}