#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, a, b; cin >> n >> a >> b;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<int> dis(n+1, INT_MAX);
    
    for(int i = 0; i < a; ++i)
    {
        int c, d; cin >> c >> d;
        adj[c].push_back({d,1});
        adj[d].push_back({c,1});
    }
    for(int i = 0; i < b; ++i)
    {
        int c, d; cin >> c >> d;
        adj[c].push_back({d,10000});
        adj[d].push_back({c,10000});
    }

    vector<int> p(n+1, -1);
    priority_queue<pair<int,int>> q;
    q.push({0, 1});
    while(!q.empty())
    {
        int x = -q.top().first;
        int v = q.top().second;
        q.pop();
        if(x >= dis[v])
            continue;
        dis[v] = x;
        for(auto [i, j]:adj[v])
        {
            int y = x + j;
            if(y < dis[i])
            {
                p[i] = v;
                q.push({-y, i});
            }
        }
    }

    int ans = 0, tmp = dis[n];
    while(tmp >= 10000)
    {
        tmp -= 10000;
        ans++;
    }
    cout << ans;
}