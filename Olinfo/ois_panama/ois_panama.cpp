#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node
{
    ll pre = -1e18;
    ll tot = 0;
    ll suf = -1e18;
    ll sub_max = -1e18;
};

node unisci(node a, node b)
{
    node res;
    res.tot = a.tot + b.tot;
    res.pre = max(a.pre, a.tot + b.pre);
    res.suf = max(b.suf, a.suf + b.tot);
    res.sub_max = max(a.suf + b.pre, max(a.sub_max, b.sub_max));
    return res;
}

struct Segment
{
    int n;
    vector<node> t;

    Segment(int _n, vector<ll> a)
    {
        for(n = 1; n < _n; n <<= 1);
        t.resize(2*n);
        for(int i = 0; i < _n; ++i) t[i+n].pre = t[i+n].tot = t[i+n].suf = t[i+n].sub_max = a[i];
        for(int i = n-1; i > 0; --i) t[i] = unisci(t[2*i], t[2*i+1]);
    }

    void update(int i, int tl, int tr, int p, int v)
    {
        if(p < tl || tr < p) return;
        if(tl == tr) t[i].pre = t[i].tot = t[i].suf = t[i].sub_max = v;
        else
        {
            int tm = (tl + tr) / 2;
            update(2*i, tl, tm, p, v);
            update(2*i+1, tm+1, tr, p, v);
            t[i] = unisci(t[2*i], t[2*i+1]);
        }
    }

    void update(int p, int v)
    {
        update(1, 0, n-1, p, v);
    }

    node query(int i, int tl, int tr, int l, int r)
    {
        if(r < tl || tr < l) return {};
        if(l <= tl && tr <= r) return t[i];
        int tm = (tl + tr) / 2;
        return unisci(query(2*i, tl, tm, l, r), query(2*i+1, tm+1, tr, l, r));
    }

    node query(int l, int r)
    {
        return query(1, 0, n-1, l, r);
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q; cin >> n >> q;
    vector<ll> a(n);
    for(auto &i: a) cin >> i;

    vector<ll> odd(n), even(n);
    for(int i = 0; i < n; ++i)
    {
        if(i & 1)
        {
            odd[i] = a[i];
            even[i] = -a[i];
        } else
        {
            odd[i] = -a[i];
            even[i] = a[i];
        }
    }

    Segment st_odd = Segment(n, odd);
    Segment st_even = Segment(n, even);
    for(int i = 0; i < q; ++i)
    {
        ll a, b, c; cin >> a >> b >> c;
        if(a == 1)
        {
            b--;
            if(b & 1)
            {
                st_odd.update(b, c);
                st_even.update(b, -c);
            } else
            {
                st_odd.update(b, -c);
                st_even.update(b, c);
            }
            
        } else if(a == 2)
        {
            b--; c--;
            cout << max(st_odd.query(b, c).sub_max, st_even.query(b, c).sub_max) << "\n";
        }
    }
}