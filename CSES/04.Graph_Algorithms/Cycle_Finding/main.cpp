#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge
{
    int a, b, cost;
};
const ll INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<Edge> edges(m);
    for(int i = 0; i < m; ++i) cin >> edges[i].a >> edges[i].b >> edges[i].cost;

    vector<ll> dist(n+1, INF);
    dist[1] = 0;
    vector<int> p(n+1, -1);
    int x;
    for(int i = 0; i < n; ++i)
    {
        x = -1;
        for(Edge e: edges)
        {
            if(dist[e.b] > dist[e.a]+e.cost)
            {
                dist[e.b] = max(-INF, dist[e.a]+e.cost);
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if(x == -1) cout << "NO\n";
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
            if(cur == y && path.size()>1) break;
        }

        reverse(begin(path), end(path));

        cout << "YES\n";
        for(auto u: path) cout << u << " ";
        cout << "\n";
    }
}
