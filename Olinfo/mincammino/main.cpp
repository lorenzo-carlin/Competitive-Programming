#include <bits/stdc++.h>
using namespace std;

void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<int>& D)
{
    vector<vector<pair<int,int>>> adj(N);
    for(int i = 0; i < M; ++i)
    {
        adj[X[i]].push_back({Y[i], P[i]});
    }

    for(int i = 0; i < N; ++i)
    {
        D[i] = INT_MAX;
    }

    priority_queue<pair<int,int>> q;

    q.push({0, 0});
    while(!q.empty())
    {
        int x = -q.top().first;
        int v = q.top().second;
        q.pop();
        if(x >= D[v])
            continue;
        D[v] = x;
        for(auto [i, j]:adj[v])
        {
            int y = x + j;
            if(y < D[i])
            {
                q.push({-y, i});
            }
        }
    }

    for(int i = 0; i < N; ++i)
    {
        if(D[i] == INT_MAX)
        {
            D[i] = -1;
        }
    }
}
