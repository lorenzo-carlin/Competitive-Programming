#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int mod = 1e9+7;
 
vector<vector<int>> adj;
vector<bool> vis;
vector<int> toposort;
 
void dfs(int node)
{
    vis[node] = true;
    for(auto el: adj[node])
    {
        if(!vis[el]) dfs(el);
    }
    toposort.push_back(node);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m; cin >> n >> m;
    adj.resize(n+1);
    vis.resize(n+1, false);
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
 
    for(int i = 1; i <= n; ++i)
    {
        if(!vis[i]) dfs(i);
    }
 
    vector<int> dp(n+1, 0);
    for(auto el: toposort)
    {
        if(el == n) dp[el] = 1;
        else
        {
            for(auto i: adj[el]) dp[el] = (dp[el] + dp[i]) % mod;
        }
    }
    cout << dp[1] << "\n";
}
