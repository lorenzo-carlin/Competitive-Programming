#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // input del grafo
    ll n, m; cin >> n >> m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    vector<ll> dist(n+1, 1e18);
    priority_queue<pair<ll,ll>> q;
    ll s, t; cin >> s >> t;
    for(ll i = 0; i < m; ++i)
    {
        ll a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    //dijkstra
    q.push({0, s});
    while(!q.empty())
    {
        ll x = -q.top().first;
        ll v = q.top().second;
        q.pop();
        if(x > dist[v])
            continue;
        dist[v] = x;
        for(auto [i, j]:adj[v])
        {
            ll y = x + j;
            if(y < dist[i])
            {
                q.push({-y, i});
            }
        }
    }

    cout << dist[t] << endl;
}