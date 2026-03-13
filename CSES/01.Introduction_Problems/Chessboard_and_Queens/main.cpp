#include <bits/stdc++.h>
using namespace std;

const int n = 8;
int sol = 0;
vector<bool> columns;
vector<bool> diag1;
vector<bool> diag2;
char mat[n][n];

void search(int x)
{
    if(x == n) sol++;
    for(int y = 0; y < n; ++y)
    {
        if(columns[y] || diag1[x+y] || diag2[x-y+n-1] || mat[x][y]=='*') continue;
        columns[y] = diag1[x+y] = diag2[x-y+n-1] = true;
        search(x+1);
        columns[y] = diag1[x+y] = diag2[x-y+n-1] = false;
    }
}

int main()
{
    columns.resize(n, false);
    diag1.resize(2*n-1, false);
    diag2.resize(2*n-1, false);

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> mat[i][j];
        }
    }

    search(0);

    cout << sol << "\n";
}