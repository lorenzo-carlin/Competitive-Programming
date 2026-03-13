#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;

    vector<ll> v(n);
    for(auto &i: v) cin >> i;

    vector<ll> dp(n); dp[0] = v[0];
    for(int i = 1; i < n; ++i)
    {
        dp[i] = max((ll) dp[i-1] + v[i], v[i]);
    }

    ll mx = -1e9;
    for(int i = 0; i < n; ++i)
    {
        mx = max(mx, dp[i]);
    }

    cout << mx << "\n";
}