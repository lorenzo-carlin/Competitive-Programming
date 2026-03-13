#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> adj;
vector<int> tin, low;
int tmr = 0;
vector<pair<int,int>> bridges;

void dfs(int v, int p)
{
    tin[v] = low[v] = tmr++;

    for(int u: adj[v])
    {
        if(u == p) continue;
        else if(tin[u] == -1)
        {
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            if(tin[v] < low[u])
                bridges.push_back({v, u});
        } else
        {
            low[v] = min(low[v], tin[u]);
        }
    }
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
