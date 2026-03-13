#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> dp(n+1); dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        int num; cin >> num;
        dp[i] = (dp[i-1] + dp[i-1-num]) % mod;
    }
    cout << dp[n] << "\n";
}