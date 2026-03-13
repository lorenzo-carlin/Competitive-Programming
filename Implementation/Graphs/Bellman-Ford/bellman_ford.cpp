// Bellman-Ford Algorithm
// Finding shortest paths with negative weights

#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int a, b, cost;
};
const int INF = 1e9;

int main()
{
    int n, m, v;
    vector<Edge> edges(m);
    for(int i = 0; i < m; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }
    

    vector<int> dist(n, INF);
    dist[v] = 0;
    vector<int> p(n, -1);

    int x;
    for(int i = 0; i < n; ++i)
    {
        x = -1;
        for(Edge e: edges)
        {
            if(dist[e.a] > dist[e.a]+e.cost)
            {
                dist[e.b] = max(-INF, dist[e.a]+e.cost);
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if(x == -1) cout << "No negative cycle from " << v << "\n";
    else
    {
        int y = x;
        for(int i = 0; i < n; ++i)
        {
            y = p[y];
        }

        vector<int> path;
        for(int cur = y; ; cur = p[cur])
        {
            path.push_back(cur);
            if(cur == y && path.size() > 1) break;
        }
        reverse(begin(path), end(path));

        cout << "Negative cycle: ";
        for(int u: path) cout << u << " ";
        cout << "\n";
    }
}