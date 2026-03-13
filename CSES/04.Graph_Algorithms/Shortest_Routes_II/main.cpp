#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll INF = 1e15;
 
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
 
    int n, m, q; cin >> n >> m >> q;
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    for(int i = 0; i < m; ++i)
    {
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    
    for(int i = 0; i < n; ++i) dist[i][i] = 0;
    
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
            }
        }
    }
 
    for(int i = 0; i < q; ++i)
    {
        ll a, b; cin >> a >> b;
        a--; b--;
        if(dist[a][b] >= INF) cout << -1 << "\n";
        else cout << dist[a][b] << "\n";
    }
 
}
