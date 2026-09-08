/*
 * Strongly Connected Components
 * Decomposes a directed graph into maximal subsets of vertices where every
 * vertex is reachable from every other vertex.
 */


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n), adjT(n);
    for(int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adjT[b].push_back(a);
    }

    vector<bool> vis(n, false);
    vector<int> order;
    auto dfs1 = [&] (auto dfs1, int v) -> void
    {
        vis[v] = true;
        for(int u: adj[v])
            if(!vis[u])
                dfs1(dfs1, u);
        order.push_back(v);
    };

    for(int i = 0; i < n; i++)
        if(!vis[i])
            dfs1(dfs1, i);
    reverse(begin(order), end(order));

    vis.assign(n, false);
    int nrSCC = 1;
    vector<int> id(n), root(n), curr_comp;
    auto dfs2 = [&] (auto dfs2, int v) -> void
    {
        vis[v] = true;
        for(int u: adjT[v])
            if(!vis[u])
                dfs2(dfs2, u);
        id[v] = nrSCC;
        curr_comp.push_back(v);
    };

    for(int i: order)
    {
        if(!vis[i])
        {
            dfs2(dfs2, i);
            nrSCC++;
            for(int v: curr_comp)
                root[v] = i;
            curr_comp.clear();
        }
    }

    vector<set<int>> adjSCC(n);
    for(int i = 0; i < n; i++)
    {
        for(int u: adj[i])
        {
            int A = root[i];
            int B = root[u];
            if(A != B)
                adjSCC[A].insert(B);
        }
    }
}
