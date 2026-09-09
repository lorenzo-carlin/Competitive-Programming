#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;
    vector<ll> v(n);
    for(auto &i: v) cin >> i;

    ll mn = -1e15;
    vector<ll> dp(n, mn);
    dp[0] = 0;

    while(k--)
    {
        auto prev = dp;
        dp.assign(n, mn);

        for(int i = 0; i < n; ++i)
        {
            for(int x = 3; x < 12; ++x)
            {
                int xx = (i + x) % n;
                dp[xx] = max(dp[xx], prev[i] + v[xx]);
            }

            for(int x = 2; x <= 12; x += 2)
            {
                int xx = (i + x) % n;
                for(int y = 3; y < 12; ++y)
                {
                    int yy = (xx + y) % n;
                    dp[yy] = max(dp[yy], prev[i] + v[xx] + v[yy]);
                }
            }

            for(int x = 2; x <= 12; x += 2)
            {
                int xx = (i + x) % n;
                for(int y = 2; y <= 12; y += 2)
                {
                    int yy = (xx + y) % n;
                    for(int z = 2; z <= 12; ++z)
                    {
                        int zz = (yy + z) % n;
                        dp[zz] = max(dp[zz], prev[i] + v[xx] + v[yy] + v[zz]);
                    }
                }
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
}