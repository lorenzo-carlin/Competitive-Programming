#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
vector<vector<int>> adj;
vector<int> open, low;
vector<bool> vis;
vector<pair<int,int>> bridges;
int t = 0;
 
void dfs(int p, int n)
{
    open[n] = low[n] = t++;
    vis[n] = true;
 
    for(int v: adj[n])
    {
        if(p == v) continue;
        if(!vis[v])
        {
            dfs(n, v);
            low[n] = min(low[n], low[v]);
            if(low[v] > open[n]) bridges.push_back({n, v});
        } else
        {
            low[n] = min(low[n], open[v]);
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m; cin >> n >> m;
    adj.resize(n+1);
    open.resize(n+1);
    low.resize(n+1);
    vis.resize(n+1, false);
 
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    dfs(0, 1);
 
    cout << bridges.size() << "\n";
    for(auto el: bridges) cout << el.first << " " << el.second << "\n";
}
