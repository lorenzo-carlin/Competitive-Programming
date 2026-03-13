#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1e18;

int main()
{
    int n, m; cin >> n >> m;
    vector<int> c(n);
    for(int &i: c) cin >> i;

    vector<vector<int>> adj(n), adjT(n);
    for(int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adjT[b].push_back(a);
    }

    vector<bool> vis(n, false);
    vector<int> order;
    auto dfs1 = [&] (auto dfs1, int v, int p) -> void
    {
        vis[v] = true;
        for(int u: adj[v])
        {
            if(vis[u]) continue;
            dfs1(dfs1, u, v);
        }
        order.push_back(v);
    };

    for(int i = 0; i < n; i++)
    {
        if(vis[i]) continue;
        dfs1(dfs1, i, -1);
    }
    reverse(begin(order), end(order));

    vector<int> component, root(n);
    auto dfs2 = [&] (auto dfs2, int v, int p) -> void
    {
        vis[v] = true;
        component.push_back(v);
        for(int u: adjT[v])
        {
            if(vis[u]) continue;
            dfs2(dfs2, u, v);
        }
    };

    vis.assign(n, false);
    vector<int> toposort;
    for(int i = 0; i < n; i++)
    {
        int x = order[i];
        if(vis[x]) continue;
        toposort.push_back(x);
        dfs2(dfs2, x, -1);
        ll tot = 0;
        for(int el: component)
        {
            root[el] = x;
            tot += c[el];
        }
        c[x] = tot;
        component.clear();
    }

    vector<set<int>> G(n);
    for(int i = 0; i < n; i++)
    {
        for(int el: adj[i])
        {
            if(root[i] != root[el])
            {
                G[root[i]].insert(root[el]);
            }
        }
    }

    int st = root[0];
    int fn = root[n-1];

    vector<ll> dp(n, -INF);
    dp[st] = c[st];

    for(int el: toposort)
    {
        if(dp[el] == -INF) continue;
        for(int u: G[el])
            dp[u] = max(dp[u], dp[el]+c[u]);
    }

    cout << dp[fn] << "\n";
}
