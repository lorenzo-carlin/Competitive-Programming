#include <bits/stdc++.h>
using namespace std;

void dfs(vector<bool> &vis, vector<vector<int>> &adj, int node)
{
    vis[node] = true;
    for(auto i: adj[node])
    {
        if(!vis[i])
        {
            dfs(vis, adj, i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis(n, false);
    int comp = 0;
    for(int i = 0; i < n; ++i)
    {
        if(!vis[i])
        {
            dfs(vis, adj, i);
            comp++;
        }
    }

    int sol = comp-1;
    cout << sol << "\n";
}