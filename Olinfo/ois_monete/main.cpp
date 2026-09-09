#include <bits/stdc++.h>
using namespace std;

int dfs(int num, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &v)
{
    vis[num] = true;
    int val = v[num];
    for(auto el:adj[num])
    {
        if(!vis[el])
        {
            val += dfs(el, adj, vis, v);
        }
    }
    return val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;
    
    vector<int> v(n);
    for(auto &i:v) cin >> i;

    vector<vector<int>> adj(n);
    vector<bool> vis(n, false);
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int mx = 0;
    for(int i = 0; i < n; ++i)
    {
        if(!vis[i])
        {
            int tmp = dfs(i, adj, vis, v);
            if(tmp > mx)
            {
                mx = tmp;
            }
        }
    }

    cout << mx << "\n";
}