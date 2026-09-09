#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);

    for(int i = 0; i < m; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    priority_queue<pair<int,int>> q;
    vector<int> dist(n, 1e9);
    q.push({0, 0});
    while(!q.empty())
    {
        int x = -q.top().first;
        int y = q.top().second;
        q.pop();

        if(x >= dist[y]) continue;
        dist[y] = x;
        
        for(auto i: adj[y])
        {
            int tmp = x + i.second;
            if(tmp < dist[i.first])
            {
                q.push({-tmp, i.first});
            }
        }
    }

    cout << dist[n-1] << "\n";
}