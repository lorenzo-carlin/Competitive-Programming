#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    map<int,int> ed;
    for(int i = 0, a, b; i < m; ++i)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ed[a] = i+1;
        ed[b] = i+1;
    }

    // cerco i bridges
    vector<bool> bridges(n, false);
    vector<bool> vis(n, false);
    vector<int> tin(n, -1);
    vector<int> low(n, -1);
    int tmr = 0;

    auto dfs = [&] (auto dfs, int v, int p) -> void
    {
        vis[v] = true;
        tin[v] = low[v] = tmr++;
        bool par_sk = false;
        
        for(int u: adj[v])
        {
            if(u == p && !par_sk)
            {
                par_sk = true;
                continue;
            }
            if(vis[u]) low[v] = min(low[v], tin[u]);
            else
            {
                dfs(dfs, u, v);
                low[v] = min(low[v], low[u]);
                if(low[u] > tin[v])
                {
                    bridges[u] = bridges[v] = true;
                }
            }
        }
    };

    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            dfs(dfs, i, -1);
        }
    }

    cout << "Bridges: ";
    for(int i = 0; i < n; ++i)
    {
        if(bridges[i]) cout << i << " ";
    }
    cout << "\n";

    vector<pair<int,int>> dist(n, {1e9, -1});
    priority_queue<array<int,3>> pq;
    for(int i = 0; i < n; ++i)
    {
        if(bridges[i])
        {
            pq.push({0, i, i});
        }
    }

    while(!pq.empty())
    {
        int d = -pq.top()[0];
        int v = pq.top()[1];
        int o = pq.top()[2];
        pq.pop();

        if(d >= dist[v].first) continue;
        dist[v] = {d, o};

        for(int u: adj[v])
        {
            if(dist[u].first > d+1)
            {
                pq.push({-(d+1), u, o});
            }
        }
    }

    int q; cin >> q;
    while(q--)
    {
        int x; cin >> x;
        x--;
        if(dist[x].first == 1e9) cout << -1 << " ";
        else cout << ed[dist[x].second] << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}

