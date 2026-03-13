#include <bits/stdc++.h>
using namespace std;

void dfs(int num, vector<bool> &v, vector<vector<int>> &adj)
{
    v[num] = true;
    for(auto i:adj[num])
    {
        if(!v[i])
        {
            dfs(i, v, adj);
        }
    }
}

int main()
{
    int t; cin >> t;
    for(int x = 0; x < t; ++x)
    {
        // input
        int n, m, l; cin >> n >> m >> l;
        vector<bool> v(n+1, false);

        vector<vector<int>> adj(n+1);
        for(int i = 0; i < m; ++i)
        {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
        }

        vector<int> knk(l);
        for(auto &i:knk) cin >> i;

        // soluzione
        for(int i = 0; i < knk.size(); ++i)
        {
            dfs(knk[i], v, adj);
        }
        
        int ans = 0;
        for(int i = 0; i <= n; ++i)
        {
            if(v[i])
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
}