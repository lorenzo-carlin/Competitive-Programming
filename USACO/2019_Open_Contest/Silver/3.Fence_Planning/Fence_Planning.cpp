#include <bits/stdc++.h>
using namespace std;

int mx_x, mn_x, mx_y, mn_y;

void dfs(int i, vector<pair<int,int>> &v, vector<bool> &vis, vector<vector<int>> &adj)
{
    vis[i] = true;
    mx_x = max(mx_x, v[i].first);
    mn_x = min(mn_x, v[i].first);
    mx_y = max(mx_y, v[i].second);
    mn_y = min(mn_y, v[i].second);
    for(auto el: adj[i])
    {
        if(!vis[el]) dfs(el, v, vis, adj);
    }
}

int main()
{
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);

    int n, m; cin >> n >> m;
    vector<pair<int,int>> v;
    for(int i = 0; i < n; ++i)
    {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis(n, false);
    int mn = 1e9;
    for(int i = 0; i < n; ++i)
    {
        mx_x = 0, mn_x = 1e9, mx_y = 0, mn_y = 1e9;
        if(!vis[i])
        {
            dfs(i, v, vis, adj);
            int p = 2*((mx_x-mn_x)+(mx_y-mn_y));
            mn = min(mn, p);
        }
    }
    cout << mn << "\n";
}