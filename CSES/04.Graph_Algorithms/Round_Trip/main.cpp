#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
vector<vector<int>> adj;
vector<bool> vis;
vector<int> tsort;
vector<int> open;
// int tmr = 0;
int l = 0, r = 0;
bool sol = false, fn = false;
 
void dfs(int node, int tmr)
{
    vis[node] = true;
    open[node] = tmr;
    
    for(auto v: adj[node])
    {
        if(fn) return;
        if(!vis[v] && !sol) dfs(v, tmr+1);
        else if(vis[v] && !sol)
        {
            if(open[node] - open[v] >= 2)
            {
                l = v, r = node;
                sol = true;
            }
        }
    }
 
    if(fn) return;
 
    if(sol)
    {
        tsort.push_back(node);
        if(node == l)
        {
            sol = false;
            fn = true;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m; cin >> n >> m;
    vis.resize(n+1, false);
    open.resize(n+1, 1e9);
    adj.resize(n+1);
 
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    for(int i = 0; i < n; ++i)
    {
        if(!adj[i].empty() && !fn)
        {
            dfs(i, 0);
        }
    }
 
    reverse(begin(tsort), end(tsort));
 
    if(tsort.empty()) cout << "IMPOSSIBLE\n";
    else
    {
        cout << tsort.size()+1 << "\n";
        for(auto el: tsort) cout << el << " ";
        cout << l << "\n";
    }
}
