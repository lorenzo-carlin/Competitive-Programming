#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n; cin >> n;
    vector<ll> v(n);
    for(auto &i: v) cin >> i;

    auto cost2 = [&] (const vector<ll> &a, int i) -> ll
    {
        return abs(a[i] - a[i+1]);
    };

    auto cost3 = [&] (const vector<ll> &a, int i) -> ll
    {
        vector<ll> tmp = {a[i], a[i+1], a[i+2]};
        sort(begin(tmp), end(tmp));
        ll ans = tmp[2]-tmp[0];
        return ans;
    };

    auto dp = [&] (const vector<ll> &a) -> ll
    {
        vector<ll> dp(n+2, 1e18);
        dp[n] = dp[n+1] = 0;
        for(int i = n-2; i >= 0; i--)
        {
            if(i == n-2) dp[i] = dp[i+2]+cost2(a, i);
            else dp[i] = min(dp[i+2]+cost2(a, i), dp[i+3]+cost3(a, i));
        }
        return dp.front();
    };

    ll mnn = dp(v);
    v.push_back(v.front());
    v.erase(v.begin());
    mnn = min(mnn, dp(v));
    v.push_back(v.front());
    v.erase(v.begin());
    mnn = min(mnn, dp(v));

    cout << mnn << "\n";
}

int main()
{
    int t; cin >> t;
    while(t--) solve();
}
