#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, l; cin >> n >> m >> l;
    vector<vector<int>> adj(n);
    vector<int> dist(n, INT_MAX);
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> police(l);
    for(int &i:police) cin >> i;

    // calcolo cammino minimo
    priority_queue<pair<int,int>> q;
    dist[0] = 0;
    q.push({0,0});
    while(!q.empty())
    {
        int x = -q.top().first;
        int y = q.top().second;
        q.pop();
        if(dist[y] < x)
            continue;
        for(int i:adj[y])
        {
            int t = x+1;
            if(police[(x+1)%l] == i)
            {
                t = x+2;
            } else
            {
                t = x+1;
            }
            if(dist[i] > t)
            {
                dist[i] = t;
                q.push({-t,i});
            }
        }
    }
    cout << dist[n-1];
}