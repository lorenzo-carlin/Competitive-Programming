#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<ll> k(n);
    for(auto &i: k) cin >> i;
    vector<vector<int>> adj(n), adjT(n);
    for(int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adjT[b].push_back(a);
    }

    vector<bool> vis(n, false);
    vector<int> order;
    auto dfs1 = [&] (auto dfs1, int v) -> void
    {
        vis[v] = true;
        for(int u: adj[v])
        {
            if(!vis[u])
            {
                dfs1(dfs1, u);
            }
        }
        order.push_back(v);
    };

    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            dfs1(dfs1, i);
        }
    }
    reverse(begin(order), end(order));

    vis.assign(n, false);
    vector<int> curr_comp, root(n), id(n);
    int tmr = 1;
    ll tot = 0;
    auto dfs2 = [&] (auto dfs2, int v) -> void
    {
        vis[v] = true;
        for(int u: adjT[v])
        {
            if(!vis[u])
            {
                dfs2(dfs2, u);
            }
        }
        id[v] = tmr;
        tot += k[v];
        curr_comp.push_back(v);
    };

    vector<ll> k1(n);
    vector<int> toposort;
    for(int i = 0; i < n; i++)
    {
        int x = order[i];
        if(!vis[x])
        {
            dfs2(dfs2, x);
            for(int u: curr_comp)
            {
                root[u] = x;
            }
            k1[x] = tot;
            toposort.push_back(x);

            curr_comp.clear();
            tot = 0;
            tmr++;
        }
    }

    vector<set<int>> adjSCC(n);
    for(int i = 0; i < n; i++)
    {
        for(int u: adj[i])
        {
            int A = root[i];
            int B = root[u];
            if(A != B)
            {
                adjSCC[A].insert(B);
            }
        }
    }

    ll ans = 0;
    vector<ll> dp(n, 0);
    int sz = toposort.size();
    for(int i = sz-1; i >= 0; i--)
    {
        int x = toposort[i];
        ll mx = 0;
        for(int u: adjSCC[x])
        {
            mx = max(mx, dp[u]);
        }
        mx += k1[x];
        dp[x] = mx;
        ans = max(ans, dp[x]);
    }

    cout << ans << "\n";
}
