#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
        v[i] = 100 + 200*v[i];
    }
    v.insert(v.begin(), 0);

    vector<pair<int,int>> dp(n+1);
    dp[0] = {0,0};
    for(int i = 1; i <= n; ++i)
    {
        if(i <= 3) dp[i] = {v[i]+dp[i-1].first,i};
        else
        {
            int mx = 0, mx_dim = -1;
            // caso in cui ne prendo 1
            int tmp1 = v[i] + dp[i-dp[i-1].second-1].first;
            if(tmp1 > mx)
            {
                mx = tmp1;
                mx_dim = 1;
            }
            // caso in cui ne prendo 2
            int tmp2 = v[i] + v[i-1] + dp[i-dp[i-2].second-2].first;
            if(tmp2 > mx)
            {
                mx = tmp2;
                mx_dim = 2;
            }
            // caso in cui ne prendo 3
            int tmp3 = v[i] + v[i-1] + v[i-2] + dp[i-dp[i-3].second-3].first;
            if(tmp3 > mx)
            {
                mx = tmp3;
                mx_dim = 3;
            }
            dp[i] = {mx,mx_dim};
        }
    }

    cout << dp[n].first << "\n";
}