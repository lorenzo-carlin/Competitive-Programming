#include <bits/stdc++.h>
#pragma GCC optimize("02")
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    int sum = 0;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
        sum += v[i];
    }

    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    dp[0][0] = true;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j <= sum; ++j)
        {
            if(j + v[i] <= sum) dp[i+1][j+v[i]] = dp[i][j] | dp[i+1][j+v[i]];
            if(j - v[i] >= 0) dp[i+1][j-v[i]] = dp[i][j] | dp[i+1][j-v[i]];
        }
    }

    if(!dp[n][0]) cout << -1;
    else
    {
        string sol;
        int cur = 0;
        for(int i = n-1; i >= 0; --i)
        {
            if(cur + v[i] <= sum && dp[i][cur+v[i]])
            {
                sol += string(v[i], ')');
                cur += v[i];
            } else if(cur - v[i] >= 0 && dp[i][cur-v[i]])
            {
                sol += string(v[i], '(');
                cur -= v[i];
            }
        }
        reverse(sol.begin(), sol.end());
        cout << sol;
    }

    cout << "\n";
}