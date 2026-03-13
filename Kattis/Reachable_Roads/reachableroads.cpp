#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[node] = true;
    for(int i:adj[node])
    {
        if(!vis[i])
        {
            dfs(i, adj, vis);
        }
    }
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m;

        // input lista di adiacenza
        vector<vector<int>> adj(n);
        for(int i = 0; i < m; ++i)
        {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // risoluzione
        int comp_conn = 0;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; ++i)
        {
            if(!vis[i])
            {
                dfs(i, adj, vis);
                comp_conn++;
            }
        }

        cout << comp_conn-1 << "\n";
    }
}