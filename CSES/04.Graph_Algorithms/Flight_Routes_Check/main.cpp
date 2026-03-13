#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj)
{
    vis[node] = true;
    for(auto el: adj[node]) if(!vis[el]) dfs(el, vis, adj);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<vector<int>> adj1(n);
    vector<vector<int>> adj2(n);
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b; a--; b--;
        adj1[a].push_back(b);
        adj2[b].push_back(a);
    }

    vector<bool> vis1(n, false);
    vector<bool> vis2(n, false);

    dfs(0, vis1, adj1);
    dfs(0, vis2, adj2);

    for(int i = 0; i < n; ++i)
    {
        if(!vis1[i])
        {
            cout << "NO\n";
            cout << 1 << " " << i+1 << "\n";
            return 0;
        }
        if(!vis2[i])
        {
            cout << "NO\n";
            cout << i+1 << " " << 1 << "\n";
            return 0;
        }
    }

    cout << "YES\n";


}