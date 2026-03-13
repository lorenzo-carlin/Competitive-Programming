#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, m; cin >> n >> m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(ll i = 0; i < m; ++i)
    {
        ll a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vector<ll> rall(n+1);
    for(ll i = 1; i <= n; ++i) cin >> rall[i];

    vector<vector<ll>> dist(n+1, vector<ll> (1001, 1e15));

    // -distanza, indice di rallentamento, nodo
    priority_queue<pair<ll,pair<ll,ll>>> q;
    q.push({-0,{1000, 1}});

    while(!q.empty())
    {
        ll d = -q.top().first;
        ll r = q.top().second.first;
        ll u = q.top().second.second;
        q.pop();

        if(dist[u][r] <= d) continue;
        dist[u][r] = d;

        if(rall[u] < r) r = rall[u];

        for(auto [i, j]: adj[u])
            q.push({-(d+r*j), {r, i}});
    }

    cout << *min_element(dist[n].begin(), dist[n].end()) << "\n";

    // for(auto el: dist) cout << el << " ";
    // cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
