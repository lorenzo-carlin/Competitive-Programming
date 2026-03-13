#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>> &adj, vector<bool> &vis, set<int> &s)
{
    vis[i] = true;
    for(auto el: adj[i])
    {
        if(vis[el] == false && s.count(el) == 0) dfs(el, adj, vis, s);
    }
}

int main()
{
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    set<int> s;
    for(int i = 0; i < n; ++i)
    {
        vector<bool> vis(n, false);
        for(int i = 0; i < n; ++i)
        {
            if(s.count(i) == 0)
            {
                dfs(i, adj, vis, s);
                break;
            }
        }
        for(int i = 0; i < n; ++i)
        {
            if(s.count(i) == 0 && vis[i] == false)
            {
                cout << "NO\n";
                break;
            }
            if(i == n-1) cout << "YES\n";
        }
        int p; cin >> p; p--;
        s.insert(p);
    }
}