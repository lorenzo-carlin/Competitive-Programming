#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, m; cin >> n >> m;

    vector<vector<pair<ll,ll>>> adj(n);
    for(int i = 0; i < m; ++i)
    {
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b,c});
    }

    vector<ll> dist(n, 1e18);
    priority_queue<pair<ll,ll>> q;
    q.push({0,0});
    while(!q.empty())
    {
        ll x = -q.top().first;
        ll y = q.top().second;
        q.pop();
        
        if(x >= dist[y]) continue;
        dist[y] = x;

        for(auto i: adj[y])
        {
            ll tmp = x+i.second;
            if(tmp < dist[i.first])
            {
                q.push({-tmp, i.first});
            }
        }
    }

    for(int i = 0; i < n; ++i)
    {
        cout << dist[i] << " ";
    }
    cout << "\n";
}