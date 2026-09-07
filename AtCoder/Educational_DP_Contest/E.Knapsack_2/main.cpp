#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, w; cin >> n >> w;

    ll a[n], b[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i];
    }

    int N = 1e5+5;
    vector<vector<ll>> dp(N, vector<ll>(n+1, 1e18));
    dp[0][0] = 0;

    //dp[i][j] = min weight for value i considering upto j items

    for(int i = 0; i < N; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            dp[i][j] = min(dp[i][j], dp[i][j-1]);
            if(i - b[j-1] >= 0)
            {
                dp[i][j] = min(dp[i][j], dp[i-b[j-1]][j-1]+a[j-1]);
            }
        }
    }

    ll sol = 0;
    for(int i = N-1; i >= 1; i--)
    {
        if(dp[i][n] <= w)
        {
            sol = i;
            break;
        }
    }

    cout << sol << "\n";
}