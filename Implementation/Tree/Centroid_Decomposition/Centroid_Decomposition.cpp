#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Centroid_Decomposition
{
    vector<set<int>> adj;
    vector<int> size;
    vector<int> par;

    Centroid_Decomposition(vector<set<int>> &adj) : adj(adj)
    {
        int n = adj.size();
        size.resize(n);
        par.resize(n);
        build(0, -1);
    }

    int dfs(int u, int p)
    {
        size[u] = 1;
        for(int v: adj[u])
        {
            if(v == p) continue;
            size[u] += dfs(v, u);
        }
        return size[u];
    }

    int find_centroid(int u, int p, int n)
    {
        for(int v: adj[u])
        {
            if(v != p && size[v] > n/2) return find_centroid(v, u, n);
        }
        return u;
    }

    void build(int u, int p)
    {
        int n = dfs(u, p);
        int centroid = find_centroid(u, p, n);
        if(p == -1) p = centroid;
        par[centroid] = p;

        vector<int> tmp(adj[centroid].begin(), adj[centroid].end());
        for(int v: tmp)
        {
            adj[centroid].erase(v);
            adj[v].erase(centroid);
            build(v, centroid);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m; cin >> m;
    vector<set<int>> adj(m);
    for(int i = 0, a, b; i < m-1; ++i)
    {
        cin >> a >> b; a--; b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    Centroid_Decomposition cen = Centroid_Decomposition(adj);
    for(int i = 0; i < m; ++i)
    {
        cout << i+1 << ":\t" << cen.par[i]+1 << "\n";
    }
}