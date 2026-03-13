#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>> &adj, pair<int,int> p, vector<bool> &vis)
{
    vis[i] = true;
    for(auto el: adj[i])
    {
        if(!vis[el] && p != make_pair(i, el) && p != make_pair(el, i)) dfs(el, adj, p, vis);
    }
}

int main()
{
    int n, m; cin >> n >> m;
    while(n != 0 || m != 0)
    {
        vector<vector<int>> adj(n);
        vector<pair<int,int>> v(m);
        for(int i = 0; i < m; ++i)
        {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            v[i] = {a, b};
        }

        bool cond = true;
        for(int i = 0; i < m; ++i)
        {
            vector<bool> vis(n, false);
            dfs(0, adj, v[i], vis);
            for(int i = 0; i < n; ++i)
            {
                if(!vis[i]) cond = false;
            }
            if(!cond)
            {
                cout << "Yes\n";
                break;
            }

            if(i == m-1) cout << "No\n";
        }

        cin >> n >> m;
    }
}