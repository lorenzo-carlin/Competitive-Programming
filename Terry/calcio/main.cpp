#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t; cin >> t;
    for(int p = 1; p <= t; ++p)
    {
        //input, inizializzazione matrice f
        int n, m, k, a, b; cin >> n >> m >> k >> a >> b;
        vector<vector<int>> f(n+1);
        for(int i = 0; i <= n; ++i)
        {
            for(int j = 0; j <= m; ++j)
            {
                f[i].push_back(0);
            }
        }
        for(int x = 0; x < k; ++x)
        {
            int c, d; cin >> c >> d;
            f[c+1][d+1]++;
        }

        //inizializzazione matrice cm
        vector<vector<int>> cm(n+1);
        for(int i = 0; i <= n; ++i)
        {
            for(int j = 0; j <= m; ++j)
            {
                if(i == 0 || j == 0)
                {
                    cm[i].push_back(0);
                } else
                {
                    cm[i].push_back((cm[i][j-1] + cm[i-1][j] + f[i][j] - cm[i-1][j-1]));
                }
            }
        }

        //ricerca del minimo
        int mn = INT_MAX;
        for(int i = a; i <= n; ++i)
        {
            for(int j = b; j <= m; ++j)
            {
                int tmp = cm[i][j] - cm[i-a][j] - cm[i][j-b] + cm[i-a][j-b];
                mn = min(mn, tmp);
            }
        }

        cout << "Case #" << p << ": " << mn << endl;
    }
}