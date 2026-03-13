#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    int ps[n+1][n+1];
    for(int i = 0; i <= n; ++i)
    {
        ps[i][0] = 0;
        ps[0][i] = 0;
    }

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            char c; cin >> c;
            ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
            if(c == '*') ps[i][j]++;
        }
    }

    for(int i = 0; i < q; ++i)
    {
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        int sol = ps[y2][x2] - ps[y1-1][x2] - ps[y2][x1-1] + ps[y1-1][x1-1];
        cout << sol << "\n";
    }
}