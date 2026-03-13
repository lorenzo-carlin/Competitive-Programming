#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0, a, b; i < m; ++i)
    {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    int ans = 1e9;
    auto bfs = [&] (int v) -> void
    {
        vector<int> dist(n, -1);
        dist[v] = 0;
        queue<int> q;
        q.push(v);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
 
            for(int p: adj[u])
            {
                if(dist[p] == -1)
                {
                    dist[p] = dist[u]+1;
                    q.push(p);
                } else if(dist[p] >= dist[u])
                {
                    ans = min(ans, dist[u]+dist[p]+1);
                }
            }
        }
    };
 
    for(int i = 0; i < n; ++i)
    {
        bfs(i);
    }
 
    ans = (ans == 1e9) ? (-1) : (ans);
 
    cout << ans << "\n";
}
