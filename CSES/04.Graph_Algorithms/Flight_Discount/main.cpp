#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define f first
#define s second

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m; cin >> n >> m;
    vector<vector<pair<ll,ll>>> adj(n);
    for(ll i = 0; i < m; ++i)
    {
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
    }

    vector<vector<ll>> dist(2, vector<ll> (n, 1e18));

    priority_queue<pair<ll,pair<ll,bool>>> pq;
    pq.push({0, {0, false}});
    while(!pq.empty())
    {
        auto el = pq.top();
        pq.pop();

        if(-el.f >= dist[0][el.s.f] && !el.s.s) continue;
        if(-el.f >= dist[1][el.s.f] && el.s.s) continue;
        
        if(!el.s.s) dist[0][el.s.f] = -el.f;
        else dist[1][el.s.f] = -el.f;

        for(auto i: adj[el.s.f])
        {
            if(!el.s.s)
            {
                pq.push({el.f-i.s,{i.f, false}});
                pq.push({el.f-(i.s/2),{i.f, true}});
            } else
            {
                pq.push({el.f-i.s,{i.f, true}});
            }
        }
    }

    cout << min(dist[0][n-1], dist[1][n-1]) << "\n";
}