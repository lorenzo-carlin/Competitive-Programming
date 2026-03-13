#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n; cin >> n;
    vector<ll> h(n);
    for(auto &i: h) cin >> i;
    h.insert(h.begin(), 0);

    vector<ll> dp(n+1, 0);
    dp[1] = h[1];
    for(ll i = 2; i <= n; i++)
    {
        dp[i] = min(dp[i-1] + h[i] - 1, dp[i-2] + h[i-1] + max(0LL, (h[i] - (i - 1))));
    }

    cout << dp.back() << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
