#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int machete(int n, int k, vector<int> p)
{
    vector<vector<int>> adj(n);
    for(int i = 1; i < n; ++i)
    {
        adj[p[i]].push_back(i);
        adj[i].push_back(p[i]);
    }

    int cnt = 0;

    auto dfs = [&] (auto dfs, int v, int p, int hh) -> int
    {
        int h = 1;

        for(int u: adj[v])
        {
            if(u == p) continue;
            h = max(h, dfs(dfs, u, v, hh+1)+1);
        }

        if(hh+h-1 <= k) return 0;

        if(h == k-1)
        {
            cnt++;
            return 0;
        }

        return h;
    };

    dfs(dfs, 0, -1, 1);

    return cnt;
}
