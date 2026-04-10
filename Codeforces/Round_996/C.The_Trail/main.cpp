#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m; cin >> n >> m;
    vector<vector<ll>> mat(n, vector<ll> (m));

    string s; cin >> s;

    vector<ll> sumRows(n, 0), sumCols(m, 0);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            sumRows[i] += mat[i][j];
            sumCols[j] += mat[i][j];
        }
    }

    vector<int> missingRows(n, 0), missingCols(m, 0);
    int x = 0, y = 0;
    missingRows[x]++;
    missingCols[y]++;
    for(int i = 0; i < n+m-2; i++)
    {
        if(s[i] == 'D') x++;
        else if(s[i] == 'R') y++;
        missingRows[x]++;
        missingCols[y]++;
    }

    x = 0, y = 0;
    if(missingRows[x] == 1)
    {
        mat[x][y] = -sumRows[x];
        sumRows[x] += mat[x][y];
        sumCols[y] += mat[x][y];
        missingRows[x]--;
        missingCols[y]--;
    } else if(missingCols[y] == 1)
    {
        mat[x][y] = -sumCols[y];
        sumRows[x] += mat[x][y];
        sumCols[y] += mat[x][y];
        missingRows[x]--;
        missingCols[y]--;
    }
    for(int i = 0; i < n+m-2; i++)
    {
        if(s[i] == 'D') x++;
        else if(s[i] == 'R') y++;

        if(missingRows[x] == 1)
        {
            mat[x][y] = -sumRows[x];
            sumRows[x] += mat[x][y];
            sumCols[y] += mat[x][y];
            missingRows[x]--;
            missingCols[y]--;
        } else if(missingCols[y] == 1)
        {
            mat[x][y] = -sumCols[y];
            sumRows[x] += mat[x][y];
            sumCols[y] += mat[x][y];
            missingRows[x]--;
            missingCols[y]--;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
