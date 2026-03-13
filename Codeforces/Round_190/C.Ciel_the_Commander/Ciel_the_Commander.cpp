#include <bits/stdc++.h>
using namespace std;

struct centroid
{
    vector<set<int>> adj;
    vector<int> par, size;
    vector<char> sol;

    centroid(vector<set<int>> &adj) : adj(adj)
    {
        int n = adj.size();
        par.resize(n);
        size.resize(n);
        sol.resize(n);
        build(0, -1, 'A');
    }

    void build(int u, int p, char c)
    {
        int n = dfs(u, p);
        int cen = findCentroid(u, p, n);
        par[cen] = p;
        sol[cen] = c;

        vector<int> tmp(adj[cen].begin(), adj[cen].end());
        for(int i: tmp)
        {
            adj[i].erase(cen);
            build(i, cen, c+1);
        }
        adj[cen].clear();
    }

    int dfs(int u, int p)
    {
        size[u] = 1;
        for(int i: adj[u])
        {
            if(i == p) continue;
            size[u] += dfs(i, u);
        }
        return size[u];
    }

    int findCentroid(int u, int p, int n)
    {
        for(int i: adj[u])
        {
            if(i != p && size[i] > n/2)
            {
                return findCentroid(i, u, n);
            }
        }
        return u;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<set<int>> adj(n);
    for(int i = 0, a, b; i < n-1; ++i)
    {
        cin >> a >> b; a--; b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    centroid C = centroid(adj);
    for(auto el: C.sol) cout << el << " ";
    cout << "\n";
}