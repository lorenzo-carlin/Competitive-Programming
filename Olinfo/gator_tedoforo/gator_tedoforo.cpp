#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0; i < m; ++i)
    {
        int a, b, c; cin >> a >> b >> c; a--; b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vector<int> dist(n, 1e9);
    priority_queue<pair<int,int>> q;
    q.push({0, 0});
    while(!q.empty())
    {
        int x = q.top().first;
        int y = q.top().second;
        q.pop();
        if(x >= dist[y]) continue;
        dist[y] = x;
        for(auto i: adj[y])
        {
            int o = x + i.second;
            int p = i.first;
            if(o < dist[p])
            {
                q.push({o, p});
            }
        }
    }

    int sol = 0;
    for(int i = 0; i < n; ++i)
    {
        if(dist[i] <= 10*(i+1)) sol++;
    }

    cout << sol << "\n";
}