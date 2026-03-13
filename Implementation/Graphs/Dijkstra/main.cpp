#include <bits/stdc++.h>
using namespace std;

int MAX = 100;
vector<vector<pair<int,int>>> adj(MAX);
vector<int> dist(MAX, INT_MAX);
priority_queue<pair<int,int>> q;

int main()
{
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int s, t; cin >> s >> t;
    q.push({0, s});
    while(!q.empty())
    {
        int x = -q.top().first;
        int v = q.top().second;
        q.pop();
        if(x >= dist[v])
            continue;
        dist[v] = x;
        for(auto [i, j]:adj[v])
        {
            int y = x + j;
            if(y < dist[i])
            {
                q.push({-y, i});
            }
        }
    }
    
    cout << dist[t] << endl;
}