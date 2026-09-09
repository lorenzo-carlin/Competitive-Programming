#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<vector<ll>> dp(n+1, vector<ll> (m+1, 0));

    for(int i = 1; i <= m; ++i) dp[1][i] = 1;

    for(int i = 2; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            dp[i][j] = dp[i][j-1];
            for(int k = (j-1)/2+1; k <= j/2 ; ++k)
            {
                dp[i][j] += dp[i-1][k];
                dp[i][j] = dp[i][j] % MOD;
            }
        }
    }

    ll sol = 0;
    for(int i = 1; i <= m; ++i) sol = (sol + dp[n][i]) % MOD;

    cout << sol << "\n";
 
}