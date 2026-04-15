#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m; cin >> n >> m;
    
    vector<vector<int>> adj(n);
    vector<array<int,2>> lanes(m);
    map<array<int,2>,int> lanes_index;
    for(int i = 0, a, b; i < m; ++i)
    {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        lanes[i] = {a, b};
        lanes_index[{a,b}] = i;
        lanes_index[{b,a}] = i;
    }

    // 1. Ricavo un path da 1 a N
    vector<bool> vis(n, false);
    vector<int> par(n, -1);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while(!q.empty())
    {
        int t = q.front();
        q.pop();

        for(int u: adj[t])
        {
            if(!vis[u])
            {
                vis[u] = true;
                par[u] = t;
                q.push(u);
            }
        }
    }

    set<int> marked_lanes;
    int idx = n-1;
    while(par[idx] != -1)
    {
        int nxt = par[idx];
        marked_lanes.insert(lanes_index[{idx,nxt}]);
        idx = nxt;
    }

    // 2. Trovo i bridges
    vis.assign(n, false);
    vector<bool> bridges(m, false);
    vector<int> tin(n, -1), low(n, -1);
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
            if(vis[u])
            {
                low[v] = min(low[v], tin[u]);
            } else
            {
                dfs(dfs, u, v);
                low[v] = min(low[v], low[u]);
                if(low[u] > tin[v])
                {
                    bridges[lanes_index[{u,v}]] = true;
                }
            }
        }
    };

    for(int i = 0; i < n; ++i)
    {
        if(!vis[i])
        {
            dfs(dfs, i, -1);
        }
    }

    // 3. Dijkstra multinodo
    vector<int> dist(n, 1e9);
    par.assign(n, -1);
    queue<array<int,2>> pq;
    for(int i = 0; i < m; ++i)
    {
        if(bridges[i] && marked_lanes.count(i))
        {
            pq.push({0, lanes[i][0]});
            pq.push({0, lanes[i][1]});
            dist[lanes[i][0]] = 0;
            dist[lanes[i][1]] = 0;
            if(par[lanes[i][0]] == -1) par[lanes[i][0]] = i;
            if(par[lanes[i][1]] == -1) par[lanes[i][1]] = i;
        }
    }
    while(!pq.empty())
    {
        int d = pq.front()[0];
        int v = pq.front()[1];
        pq.pop();

        for(int u: adj[v])
        {
            if(dist[u] > (d+1))
            {
                dist[u] = d+1;
                par[u] = par[v];
                pq.push({dist[u], u});
            }
        }
    }

    // 4. Query
    int qq; cin >> qq;
    while(qq--)
    {
        int x; cin >> x;
        x--;

        if(dist[x] == 1e9) cout << -1 << " ";
        else cout << par[x]+1 << " ";
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
