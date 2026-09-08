/*
 * Articulation Points
 * Finds vertices whose removal increases the number of connected components
 * in an undirected graph using DFS and low-link values.
 */


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> adj;
vector<int> tin, low;
int tmr = 0;
set<int> articulation_points;

void dfs(int v, int p)
{
    tin[v] = low[v] = tmr++;
    int children = 0;

    for(int u: adj[v])
    {
        if(u == p) continue;
        else if(tin[u] == -1)
        {
            dfs(u, v);
            children++;
            low[v] = min(low[v], low[u]);
            if(p != -1 && tin[v] <= low[u])
                articulation_points.insert(v);
        } else
        {
            low[v] = min(low[v], tin[u]);
        }
    }

    if(p == -1 && children > 1)
        articulation_points.insert(v);
}

int main()
{
    cin >> n >> m;
    adj.resize(n);
    tin.assign(n, -1);
    low.assign(n, -1);
    for(int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1);
}
