#include <bits/stdc++.h>
#pragma GCC optimize("02")
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(auto &i: v) cin >> i;

    vector<unordered_set<int>> mp(n+1);
    int m; cin >> m;
    while(m--)
    {
        int a, b; cin >> a >> b;
        mp[a].insert(b);
    }

    if(k == 1)
    {
        if(!mp[1].count(1)) cout << 0 << "\n";
        else
        {
            int sol = 0;
            for(int i = 0; i < n-1; ++i)
            {
                if(v[i] != 1 && v[i+1] != 1)
                {
                    cout << 0 << "\n";
                    return 0;
                }
                if(v[i] == 1) sol++;
            }
            if(v.back() == 1) sol++;

            cout << sol << "\n";
        }
    } else
    {
        vector<int> dp(n, 0);
        for(int i = n-2; i >= 0; i--)
        {
            if(mp[v[i]].count(v[i+1])) dp[i] = max(dp[i], dp[i+1]+1);
            if(i == n-2) continue;
            if(mp[v[i]].count(v[i+2])) dp[i] = max(dp[i], dp[i+2]+1);
        }

        if(dp[0] == 0 && dp[1] == 0) cout << 0 << "\n";
        else cout << max(dp[0]+1, dp[1]+1) << "\n";
    }
}