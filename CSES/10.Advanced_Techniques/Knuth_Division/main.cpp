#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
constexpr ll INF = 1e15;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n; cin >> n;
    vector<int> v(n);
    for(int &i: v) cin >> i;
 
    vector<ll> ps(n+1);
    ps[0] = 0;
    for(int i = 1; i <= n; ++i)
    {
        ps[i] = (ps[i-1]+v[i-1]);
    }
 
    auto sum = [&] (int l, int r) -> ll
    {
        return (ps[r+1]-ps[l]);
    };
 
    ll dp[n][n];
    int opt[n][n];
 
    for(int i = 0; i < n; ++i)
    {
        dp[i][i] = 0;
        opt[i][i] = i;
    }
 
    for(int l = 2; l <= n; ++l)         // lunghezza degli intervalli
    {
        for(int i = 0; i+l <= n; ++i)   // punto di partenza degli intervalli
        {
            int j = i+l-1;              // punto di arrivo degli intervalli
            dp[i][j] = INF;
            for(int k = opt[i][j-1]; k <= min(opt[i+1][j], n-2); ++k)
            {
                if(dp[i][j] > dp[i][k] + dp[k+1][j])
                {
                    dp[i][j] = dp[i][k] + dp[k+1][j];
                    opt[i][j] = k;
                }
            }
            dp[i][j] += sum(i, j);
        }
    }
 
    cout << dp[0][n-1] << "\n";
}
