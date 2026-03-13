#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    int t = 0;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        t += v[i];
    }

    sort(rbegin(v), rend(v));

    vector<vector<ll>> dp(n, vector<ll> (t));
    vector<vector<bool>> memo(n, vector<bool> (t, false));

    auto solve = [&] (auto solve, int i, int j) -> ll
    {
        if(j <= 0) return 1;
        if(i >= n) return 0;

        if(memo[i][j]) return dp[i][j];
        memo[i][j] = true;

        ll a = solve(solve, i+1, j-v[i]);
        ll b = solve(solve, i+1, j);

        return dp[i][j] = (a + b);
    };

    ll ans = solve(solve, 0, t/2 + 1);

    cout << ans << "\n";
}
