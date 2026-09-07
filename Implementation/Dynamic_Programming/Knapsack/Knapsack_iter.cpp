#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, w; cin >> n >> w;

    vector<vector<ll>> dp(w+1, vector<ll>(n+1, 0));
    ll a[n], b[n];
    for(int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    
    ll sol = 0;
    for(int i = 1; i <= w; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
            if(i - b[j-1] >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i-b[j-1]][j-1]+a[j-1]);
            }
            sol = max(sol, dp[i][j]);
        }
    }
    cout << sol << "\n";
    return 0;
}