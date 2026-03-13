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
    for(int i = 1; i <= x; ++i)
    {
        int sol = 0;
        for(auto el: coins) if(i-el >= 0) sol = (sol + dp[i-el]) % mod;
        dp[i] = sol;
    }

    cout << dp[x] << "\n";
}