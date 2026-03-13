#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1e15;

struct node
{
    ll sum =    0;
    ll mn  =  INF;
    ll mx  = -INF;

    bool set = false;
    ll setv;

    bool lazy = false;
    ll lazyv;

    node() {}
    node(int v)
    {
        sum = mn = mx = v;
    }
};

node merge(node a, node b)
{
    node c;
    c.sum = a.sum + b.sum;
    c.mn = min(a.mn, b.mn);
    c.mx = max(a.mx, b.mx);

    return c;
}

struct Segment
{
    int n;
    vector<node> t;

    Segment() {}
    Segment(vector<ll> v)
    {
        int _n = v.size();
        for(n = 1; n <= _n; n <<= 1);
        t.resize(2*n);
        for(int i = 0; i < _n; i++)
            t[i] = node(v[i]);
        for(int i = n-1; i > 0; i--)
            t[i] = merge(t[2*i], t[2*i+1]);
    }

    void propaga(int i, int tl, int tr)
    {
        // set
        if(t[i].set)
        {
            t[i].sum = (tl - tr + 1)*t[i].setv;
            t[i].mn = t[i].mx = t[i].setv;
            t[i].set = false;
            t[2*i].set = t[2*i+1].set = true;
            t[2*i].lazy = t[2*i+1].lazy = false;
            t[2*i].lazyv = t[2*i+1].lazyv = 0;
            t[2*i].setv = t[2*i+1].setv = t[i].setv;
        }
        // lazy
        if(t[i].lazy)
        {
            t[i].sum += (tl - tr + 1)*t[i].lazyv;
            t[i].mn += t[i].lazy;
            t[i].mx += t[i].lazy;
            t[i].lazy = false;
            t[i].lazyv = 0;
            t[2*i].lazy = t[2*i+1].lazy = true;
            t[2*i].lazyv += t[i].lazyv;
            t[2*i+1].lazyv += t[i].lazyv;
        }
    }

    ll get_sum(int i, int tl, int tr, int l, int r)
    {
        propaga(i, tl, tr);
        if(tr < l || r < tl) return 0;
        if(l <= tl && tr <= r) return t[i].sum;
        int tm = (tl + tr) / 2;
        return get_sum(2*i, tl, tm, l, r) + get_sum(2*i+1, tm+1, tr, l, r);
    }

    ll get_sum(int l, int r)
    {
        return get_sum(1, 0, n-1, l, r);
    }

    void add(int i, int tl, int tr, int l, int r, ll x)
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
            add(2*i, tl, tm, l, r, x);
            add(2*i+1, tm+1, tr, l, r, x);
            t[i] = merge(t[2*i], t[2*i+1]);
        }
    }

    void add(int l, int r, ll x)
    {
        add(1, 0, n-1, l, r, x);
    }

    void set_range(int i, int tl, int tr, int l, int r, ll x)
    {
        propaga(i, tl, tr);
        if(tr < l || r < tl) return;
        if(l <= tl && tr <= r)
        {
            t[i].set = true;
            t[i].setv = x;
        } else
        {
            int tm = (tl + tr) / 2;
            set_range(2*i, tl, tm, l, r, x);
            set_range(2*i+1, tm+1, tr, l, r, x);
            t[i] = merge(t[2*i], t[2*i+1]);
        }
    }

    void set_range(int l, int r, ll x)
    {
        set_range(1, 0, n-2, l, r, x);
    }

    ll get_min(int i, int tl, int tr, int l, int r)
    {
        propaga(i, tl, tr);
        if(tr < l || r < tl) return INF;
        if(l <= tl && tr <= r) return t[i].mn;
        int tm = (tl + tr) / 2;
        return min(get_min(2*i, tl, tm, l, r), get_min(2*i+1, tm+1, tr, l, r));
    }

    ll get_min(int l, int r)
    {
        return get_min(1, 0, n-1, l, r);
    }

    ll lower_bound(int i, int tl, int tr, int l, int r, ll x)
    {
        propaga(i, tl, tr);
        if(tr < l || r < tl) return -1;
        if(t[i].mn > x) return -1;
        if(tl == tr) return tl;
        int tm = (tl + tr) / 2;
        int sx = lower_bound(2*i, tl, tm, l, r, x);
        if(sx != -1) return sx;
        return lower_bound(2*i+1, tm+1, tr, l, r, x);
    }

    ll lower_bound(int l, int r, ll x)
    {
        return lower_bound(1, 0, n-1, l, r, x);
    }

};

Segment seg;

void init(vector<ll> a)
{
    seg = Segment(a);
}

ll get_sum(int l, int r)
{
    return seg.get_sum(l, r);
}

void add(int l, int r, ll x)
{
    seg.add(l, r, x);
}

void set_range(int l, int r, ll x)
{
    seg.set_range(l, r, x);
}

ll get_min(int l, int r)
{
    return seg.get_min(l, r);
}

int lower_bound(int l, int r, ll x)
{
    return seg.lower_bound(l, r, x);
}
