#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Segment
{
    vector<ll> t;
    ll n;

    Segment() {}

    Segment(ll _n)
    {
        for(n = 1; n <= _n; n <<= 1);
        t.resize(2*n, 0);
    }

    void update(ll i, ll tl, ll tr, ll p, ll v)
    {
        if(tl == p && tr == p) t[i] += v;
        else if(p < tl || tr < p) return;
        else
        {
            ll tm = (tl + tr) / 2;
            update(2*i, tl, tm, p, v);
            update(2*i+1, tm+1, tr, p, v);
            t[i] = t[2*i]+t[2*i+1];
        }
    }

    void update(ll p, ll v)
    {
        update(1, 0, n-1, p, v);
    }

    ll query(ll i, ll tl, ll tr, ll l, ll r)
    {
        if(r < tl || tr < l) return 0;
        if(l <= tl && tr <= r) return t[i];
        ll tm = (tl + tr) / 2;
        return query(2*i, tl, tm, l, r) + query(2*i+1, tm+1, tr, l, r);
    }

    ll query(ll l, ll r)
    {
        return query(1, 0, n-1, l, r);
    }
};

ll alleggerisci(int n, int m, vector<int> v, vector<int> l, vector<int> r, vector<ll> k)
{
    Segment seg = Segment(n);

    // intervalli[i] = {fine, inizio, costo}
    vector<array<ll,3>> intervalli;

    // controllo quali intervalli sono sbilanciati
    vector<ll> ps(n+1, 0);
    for(ll i = 0; i < n; ++i) ps[i+1] = (ll)(ps[i] + (ll)v[i]);
    for(ll i = 0; i < m; ++i)
    {
        ll tmp = ps[r[i]+1]-ps[l[i]];
        if(tmp > k[i])
        {
            intervalli.push_back({(ll)r[i], (ll)l[i], tmp-k[i]});
        }
    }

    // ordino gli intervalli per ordine di fine
    stable_sort(begin(intervalli), end(intervalli));

    // analizzo gli intervalli uno ad uno
    ll ans = 0;
    for(auto intervallo: intervalli)
    {
        ll mancanti = intervallo[2] - seg.query(intervallo[1], intervallo[0]);
        if(mancanti > 0)
        {
            ans += mancanti;
            seg.update(intervallo[0], mancanti);
        }
    }

    return ans;
}