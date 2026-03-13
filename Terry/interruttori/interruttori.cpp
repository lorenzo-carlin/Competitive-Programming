#include <bits/stdc++.h>
using namespace std;

int MAX = 1e5;
vector<vector<int>> adj(MAX);
vector<int> dist(MAX,-1);

void bfs(int n, vector<vector<int>> &adj, vector<int> &dist)
{
    queue<int> q;
    q.push(n);
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        for(auto i:adj[t])
        {
            if((dist[t]+1 < dist[i]) || dist[i]==-1)
            {
                dist[i] = dist[t]+1;
                q.push(i);
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for(int x = 1; x <= t; ++x)
    {
        int n, a, b; cin >> n >> a >> b;
        vector<vector<int>> adj(n);
        vector<int> dist(n, -1);
        vector<int> v;
        for(int i = 0; i < a; ++i)
        {
            int p; cin >> p;
            v.push_back(p);
        }
        for(int i = 0; i < b; ++i)
        {
            int s, f; cin >> s >> f;
            adj[s].push_back(f);
            adj[f].push_back(s);
        }
        for(int i = 0; i < a; ++i)
        {
            int tmp = v[i];
            dist[tmp] = 0;
            bfs(tmp, adj, dist);
        }
        int mx = -1, mx_n = -1;
        for(int i = 0; i < n; ++i)
        {
            //cout << dist[i] << "\n";
            if(dist[i] > mx)
            {
                mx = dist[i];
                mx_n = i;
            }
        }
        cout << "Case #" << x << ": " << mx_n << " " << mx+1 << "\n";
    }
}