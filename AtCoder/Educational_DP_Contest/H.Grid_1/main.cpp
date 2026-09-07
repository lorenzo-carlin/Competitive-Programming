#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9+7;

int main()
{
    int h, w; cin >> h >> w;

    char mat[h][w];
    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            cin >> mat[i][j];
        }
    }

    ll dp[h][w];
    fill(*dp, *dp+h*w, 0);
    dp[0][0] = 1;
    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            if((i == 0 && j == 0) || mat[i][j] == '#')
            {
                continue;
            } else if(i == 0)
            {
                dp[i][j] = dp[i][j-1];
            } else if(j == 0)
            {
                dp[i][j] = dp[i-1][j];
            } else
            {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
            }
        }
    }

    ll sol = dp[h-1][w-1];
    cout << sol << "\n";
}