#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;
    vector<ll> v(n);
    for(ll &i: v) cin >> i;

    auto possible = [&] (ll val) -> bool
    {
        vector<ll> dp(n+1, 0);
        ll cnt = 0;
        for(int i = 0; i < n; i++)
        {
            dp[i+1] = max(dp[i] + v[i], v[i]);
            if(dp[i+1] > val)
            {
                cnt += dp[i+1]-val;
                dp[i+1] = val;
            }
        }

        return cnt <= k;
    };


    ll l = -1e18, r = 1e18;
    while(r - l > 1)
    {
        ll m = (l + r) / 2;
        if(possible(m))
            r = m;
        else
            l = m;
    }

    if(possible(l))
        cout << l << "\n";
    else
        cout << r << "\n";
}
