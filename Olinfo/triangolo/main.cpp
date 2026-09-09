#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int mat[n][n];
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(j > i)
            {
                mat[i-1][j-1] = -1;
            } else
            {
                cin >> mat[i-1][j-1];
            }
        }
    }

    // soluzione
    for(int i = n-2; i >= 0; --i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(mat[i][j] == -1)
            {
                break;
            } else
            {
                mat[i][j] += max(mat[i+1][j], mat[i+1][j+1]);
            }
        }
    }

    cout << mat[0][0] << "\n";
}