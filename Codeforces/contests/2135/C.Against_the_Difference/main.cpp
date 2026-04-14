#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n; cin >> n;
    vector<int> v(n);
    for(auto &i: v) cin >> i;

    vector<vector<int>> occ(n+1);
    vector<int> dp(n, 0);
    dp[0] = (v[0] == 1) ? (1) : (0);
    occ[v[0]].push_back(0);
    for(int i = 1; i < n; ++i)
    {
        dp[i] = dp[i-1];

        int x = v[i];
        occ[x].push_back(i);
        int sz = occ[x].size();

        if(sz >= x)
        {
            int k = occ[x][sz-x];
            if(k == 0) dp[i] = max(dp[i], x);
            else dp[i] = max(dp[i], dp[k-1]+x);
        }
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
