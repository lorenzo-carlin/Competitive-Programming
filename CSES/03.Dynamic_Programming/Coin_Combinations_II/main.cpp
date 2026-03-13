#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for(auto &i: coins) cin >> i;

    vector<int> dp(x+1, 0);
    dp[0] = 1;
    for(auto el: coins)
        for(int i = 1; i <= x; ++i)
            if(i-el >= 0) dp[i] = (dp[i] + dp[i-el]) % mod;
    
    cout << dp[x] << "\n";
}