#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = (1LL << 60);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> c(n);
    for (ll &i : c) cin >> i;

    vector<vector<int>> adj(n), adjT(n);
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adjT[b].push_back(a);
    }

    // ---------- Kosaraju ----------
    vector<bool> vis(n, false);
    vector<int> order;

    auto dfs1 = [&](auto self, int v) -> void
    {
        vis[v] = true;
        for (int u : adj[v])
            if (!vis[u])
                self(self, u);
        order.push_back(v);
    };

    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs1(dfs1, i);

    reverse(order.begin(), order.end());

    vector<int> root(n);
    vector<int> component;
    vis.assign(n, false);

    auto dfs2 = [&](auto self, int v) -> void
    {
        vis[v] = true;
        component.push_back(v);
        for (int u : adjT[v])
            if (!vis[u])
                self(self, u);
    };

    for (int x : order)
    {
        if (vis[x]) continue;

        component.clear();
        dfs2(dfs2, x);

        ll sum = 0;
        for (int v : component)
        {
            root[v] = x;
            sum += c[v];
        }
        c[x] = sum;
    }

    // ---------- DAG delle SCC ----------
    vector<vector<int>> G(n);
    vector<int> indeg(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j : adj[i])
        {
            if (root[i] != root[j])
            {
                G[root[i]].push_back(root[j]);
                indeg[root[j]]++;
            }
        }
    }

    // ---------- Topological sort del DAG ----------
    queue<int> q;
    vector<int> topo;

    for (int i = 0; i < n; i++)
        if (indeg[i] == 0 && c[i] > 0)
            q.push(i);

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : G[u])
            if (--indeg[v] == 0)
                q.push(v);
    }

    // ---------- DP sul DAG ----------
    int st = root[0];
    int fn = root[n - 1];

    vector<ll> dp(n, -INF);
    dp[st] = c[st];

    for (int u : topo)
    {
        if (dp[u] == -INF) continue;
        for (int v : G[u])
            dp[v] = max(dp[v], dp[u] + c[v]);
    }

    cout << dp[fn] << "\n";
    return 0;
}

