/*
 * Maximum Subarray Sum
 * Finds the contiguous subarray with the maximum possible sum.
 */


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for(auto &i:v) cin >> i;

    vector<int> dp(n,0);
    dp[0] = v[0];
    int ans = 0;
    for(int i = 1; i < n; ++i)
    {
        dp[i] = max(v[i], dp[i-1]+v[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
}
