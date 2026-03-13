#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, x; cin >> n >> x;
    vector<int> c(n), p(n);
    for(auto &i: c) cin >> i;
    for(auto &i: p) cin >> i;
 
    vector<int> dp(x+1, 0), last(x+1, 0);
    for(int i = 1; i <= n; ++i)
    {
        last = dp;
        for(int j = 1; j <= x; ++j)
        {
            dp[j] = last[j];
            if(j - c[i-1] >= 0)
                dp[j] = max(dp[j], last[j - c[i-1]]+p[i-1]);
        }
    }
    cout << dp[x] << "\n";
}
