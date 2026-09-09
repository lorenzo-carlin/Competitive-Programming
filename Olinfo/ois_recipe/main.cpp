#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //input
    int n, m; cin >> m >> n;
    int mat[n][m];
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> mat[i][j];
        }
    }

    //conversione
    double conv[n][m];
    for(int i = 0; i < n; ++i)
    {
        double sum = 0.00;
        for(int j = 0; j < m; ++j)
        {
            sum += mat[i][j];
        }
        double fact = (double) (1000000 / sum);
        for(int j = 0; j < m; ++j)
        {
            conv[i][j] = (double) (mat[i][j] * fact);
        }
    }

    //calcolo medie
    vector<int> ans(m, 0);
    for(int j = 0; j < m; ++j)
    {
        double sum = 0.00;
        for(int i = 0; i < n; ++i)
        {
            sum += conv[i][j];
        }
        ans[j] = (int) sum / n;
    }

    //output
    for(int x = 0; x < ans.size(); ++x)
    {
        cout << ans[x] << " ";
    }
}