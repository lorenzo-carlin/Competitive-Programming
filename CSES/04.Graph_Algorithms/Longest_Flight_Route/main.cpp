#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);

    for(int i = 0, a, b; i < m; ++i)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b);
    }

    vector<int> toposort;
    vector<bool> vis(n, false);
    auto topo = [&] (auto topo, int v, int p) -> void
    {
        vis[v] = true;
        for(int u: adj[v])
        {
            if(u == p) continue;
            if(vis[u]) continue;
            topo(topo, u, v);
        }
        toposort.push_back(v);
    };

    for(int i = 0; i < n; ++i)
    {
        if(vis[i]) continue;
        topo(topo, 0, -1);
    }

    vector<int> dp(n, -1e9), nxt(n, -1);
    dp[n-1] = 1;
    for(int i = 0; i < n; ++i)
    {
        int x = toposort[i];
        int mn = -1e9;
        for(int u: adj[x])
        {
            if(dp[u] == -1e9) continue;
            if(dp[u]+1 > dp[x])
            {
                dp[x] = dp[u]+1;
                nxt[x] = u;
            }
        }
    }

    if(dp[0] == -1e9)
    {
        cout << "IMPOSSIBLE\n";
    } else
    {
        cout << dp[0] << "\n";
        int idx = 0;
        while(idx != -1)
        {
            cout << idx+1 << " ";
            idx = nxt[idx];
        }
        cout << "\n";
    }
}
