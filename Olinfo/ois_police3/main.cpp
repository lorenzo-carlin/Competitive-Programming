#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> t)
{
    int dp[n+1];
    t.insert(t.begin(), 0);
    int sum = 0;
    for(int i = 0; i <= n; ++i)
    {
        if(i <= 1)
            dp[i] = t[i];
        if(i > 1)
            dp[i] = max(dp[i-1], dp[i-2] + t[i]);
        sum += t[i];
    }
    int ans = sum - dp[n];
    return ans;
}

int main()
{
    int n; cin >> n;
    vector<int> t(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> t[i];
    }
    int ans = solve(n, t);
    cout << ans;
    return 0;
}