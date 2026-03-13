#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int m, n, k; cin >> m >> n >> k;

    char mat[m][n];
    char sol[k*m][k*n];

    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> mat[i][j];
            for(int x = 0; x < k; ++x)
            {
                for(int y = 0; y < k; ++y)
                {
                    sol[k*i+x][k*j+y] = mat[i][j];
                }
            }
        }
    }

    for(int i = 0; i < k*m; ++i)
    {
        for(int j = 0; j < k*n; ++j)
        {
            cout << sol[i][j];
        }
        cout << "\n";
    }
}