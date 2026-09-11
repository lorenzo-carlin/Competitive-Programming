#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for(int cas = 1; cas <= t; ++cas)
    {
        int n, m; cin >> n >> m;
        vector<vector<int>> adj(n);
        for(int i = 0, a, b; i < m; ++i)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> nav(n);
        for(auto &i: nav) cin >> i;

        vector<int> dist(n, INF);
        
        priority_queue<array<int,3>> q;
        // <-dist, nodo, saldo_curr>
        q.push({0, 0, 0});

        while(!q.empty())
        {
            int d = -q.top()[0];
            int node = q.top()[1];
            int saldo = q.top()[2];
            q.pop();

            if(d >= dist[node]) continue;
            dist[node] = d;

            for(int el: adj[node])
            {
                // a piedi
                q.push({-(d+1), el, saldo+1});

                // navetta (se può)
                if(saldo >= nav[node])
                {
                    q.push({-d, el, 0});
                }
            }
        }

        // cout << "\n";
        // for(auto el: dist)
        // {
        //     cout << el << "\n";
        // }
        // cout << "\n";


        int sol = dist[n-1];

        cout << "Case #" << cas << ": " << sol << "\n";
    }
    
    
    return 0;
}