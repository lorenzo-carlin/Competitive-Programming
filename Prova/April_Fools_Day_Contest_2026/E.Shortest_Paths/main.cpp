#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> dist(n+1, vector<int> (n+1, 1e9));
    
    for(int i = 0, a, b, c; i < m; i++)
    {
        cin >> a >> b >> c;
        dist[a][b] = c;
        dist[b][a] = c;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int k = 1; k <= n; k++)
        {
            for(int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i = 2; i <= n; i++)
    {
        cout << ((dist[1][i] == 1e9) ? (-1) : (dist[1][i])) << "\n";
    }
}
