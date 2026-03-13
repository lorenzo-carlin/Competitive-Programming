#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for(auto &i: coins) cin >> i;

    vector<int> dp(x+1, 1e9);
    dp[0] = 0;
    for(int i = 1; i <= x; ++i)
        for(auto el: coins)
           if(i-el >= 0) dp[i] = min(dp[i], dp[i-el]+1);
    
    if(dp[x] == 1e9) cout << -1 << "\n";
    else cout << dp[x] << "\n";
}