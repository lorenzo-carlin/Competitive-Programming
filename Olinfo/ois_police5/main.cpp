#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, lim; cin >> n >> m >> lim;
    vector<vector<pair<int,pair<int,bool>>>> adj(n);
    
    for(int i = 0; i < m; ++i)
    {
        int a, b, c, d; cin >> a >> b >> c >> d;
        adj[a].push_back({b,{c,d}});
    }

    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty())
    {
        int x = -q.top().first;
        int y = q.top().second;
        q.pop();
        if(x > dist[y]) continue;
        dist[y] = x;
        for(auto i:adj[y])
        {
            int t = x + i.second.first;
            if(t < dist[i.first])
            {
                if((i.second.second == true && t > lim) == false)
                {
                    q.push({-t, i.first});
                }
            }
        }
    }
    if(dist[n-1] == INT_MAX) dist[n-1] = -1;
    cout << dist[n-1] << "\n";
}