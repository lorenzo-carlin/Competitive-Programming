#include <bits/stdc++.h>
using namespace std;

int raggiungi(int N, int M, int A[], int B[], int inizio[], int fine[])
{
    vector<vector<pair<int,pair<int,int>>>> adj(N);
    for(int i = 0; i < M; ++i)
    {
        adj[A[i]].push_back({B[i], {inizio[i], fine[i]}});
        adj[B[i]].push_back({A[i], {inizio[i], fine[i]}});
    }

    int st = 0, fn = N-1;
    vector<int> dist(N, 1e9);
    priority_queue<pair<int,int>> q;
    q.push({0, st});

    while(!q.empty())
    {
        int x = -q.top().first;
        int y = q.top().second;
        q.pop();
        if(x >= dist[y]) continue;
        dist[y] = x;
        for(auto i: adj[y])
        {
            if(i.second.first <= x && i.second.second > x)
            {
                if(x+1 < dist[i.first])
                {
                    q.push({-(x+1), i.first});
                }
            } else if(i.second.first > x)
            {
                if(i.second.first+1 < dist[i.first]);
                {
                    q.push({-(i.second.first+1), i.first});
                }
            }
        }
    }

    if(dist[fn] == 1e9) dist[fn] = -1;
    return dist[fn];
}

int main()
{
    int n, m; cin >> n >> m;
    int a[m], b[m], inizio[m], fine[m];
    for(int i = 0; i < m; ++i)
    {
        int c, d, e, f; cin >> c >> d >> e >> f;
        a[i] = c;
        b[i] = d;
        inizio[i] = e;
        fine[i] = f;
    }

    cout << raggiungi(n, m, a, b, inizio, fine) << "\n";
}