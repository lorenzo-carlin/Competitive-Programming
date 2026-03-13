#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<int> &dp, vector<bool> &vis, int node)
{
    vis[node] = true;

    for(auto i: adj[node])
    {
        if(!vis[i])
        {
            dfs(adj, dp, vis, i);
        }
        dp[node] = max(dp[node], dp[i]+1);
    }
}

int main()
{
    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
    }

    vector<int> dp(n, 0);
    vector<bool> vis(n, false);

    for(int i = 0; i < n; ++i)
    {
        if(!vis[i])
        {
            dfs(adj, dp, vis, i);
        }
    }

    int mx = 0;
    for(int i = 0; i < n; ++i)
    {
        if(dp[i] > mx) mx = dp[i];
    }

    cout << mx << "\n";
}