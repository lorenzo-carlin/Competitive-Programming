#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define f first
#define s second

ll mod = 1e9+7;
ll INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m; cin >> n >> m;
    vector<vector<pair<ll,ll>>> adj(n);
    for(int i = 0; i < m; ++i)
    {
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
    }

    vector<array<ll, 4>> dist(n, {INF, 0, INF, 0});
    // dist[i][0] = distanza minima per arrivare al nodo i
    // dist[i][1] = numero dei percorsi per arrivare al nodo i con dist[i][0]
    // dist[i][2] = numero minimo di nodi da visitare per arrivare al nodo i con dist[i][0]
    // dist[i][3] = numero massimo di nodi da visitare per arrivare al nodo i con dist[i][0]

    dist[0][0] = 0;
    dist[0][1] = 1;
    dist[0][2] = 0;
    dist[0][3] = 0;

    priority_queue<pair<ll,ll>> q;
    // q.f = -distanza
    // q.s = nodo attuale
    q.push({-0, 0});
    while(!q.empty())
    {
        ll d = -q.top().f;
        ll n = q.top().s;
        q.pop();

        for(auto v: adj[n])
        {
            if((d + v.s) > dist[v.f][0]) continue;

            if((d + v.s) == dist[v.f][0])
            {
                dist[v.f][1] = (dist[v.f][1] + dist[n][1]) % mod;
                dist[v.f][2] = min(dist[v.f][2], dist[n][2]+1);
                dist[v.f][3] = max(dist[v.f][3], dist[n][3]+1);

            } else if((d + v.s) < dist[v.f][0])
            {
                dist[v.f][0] = d+v.s;
                dist[v.f][1] = dist[n][1];
                dist[v.f][2] = dist[n][2]+1;
                dist[v.f][3] = dist[n][3]+1;

                q.push({-(d+v.s), v.f});
            }
        }
    }

    cout << dist[n-1][0] << " " << dist[n-1][1] << " " << dist[n-1][2] << " " << dist[n-1][3] << "\n";
}