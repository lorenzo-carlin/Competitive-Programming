#include <bits/stdc++.h>
using namespace std;

int MAX = 1e5;
vector<vector<int>> dp(3);
vector<int> a(MAX);
vector<int> b(MAX);
vector<int> c(MAX);
int n;

int vacation(int num, char last)
{
    if(last == 'a')
    {
        if(dp[0][num] != -1)
            return dp[0][num];
        if(num == n-1)
        {
            dp[0][num] = max(b[n-1], c[n-1]);
            return dp[0][num];
        } else
        {
            dp[0][num] = max(vacation(num+1, 'b') + b[num], vacation(num+1, 'c') + c[num]);
            return dp[0][num];
        }
    }
    if(last == 'b')
    {
        if(dp[1][num] != -1)
            return dp[1][num];
        if(num == n-1)
        {
            dp[1][num] = max(a[n-1], c[n-1]);
            return dp[1][num];
        } else
        {
            dp[1][num] = max(vacation(num+1, 'a') + a[num], vacation(num+1, 'c') + c[num]);
            return dp[1][num];
        }
    }
    if(last == 'c')
    {
        if(dp[2][num] != -1)
            return dp[2][num];
        if(num == n-1)
        {
            dp[2][num] = max(a[n-1], b[n-1]);
            return dp[2][num];
        } else
        {
            dp[2][num] = max(vacation(num+1, 'a') + a[num], vacation(num+1, 'b') + b[num]);
            return dp[2][num];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int a0, b0, c0; cin >> a0 >> b0 >> c0;
        a[i] = a0; b[i] = b0; c[i] = c0;
        dp[0].push_back(-1); dp[1].push_back(-1); dp[2].push_back(-1);
    }
    int a1 = vacation(0, 'a');
    int b1 = vacation(0, 'b');
    int c1 = vacation(0, 'c');
    int ans = max(a1, b1); ans = max(ans, c1);
    cout << ans;
}