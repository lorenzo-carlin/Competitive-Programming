#include <bits/stdc++.h>
using namespace std;

int MAX = 4100;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, B; cin >> N >> B;
    int a[N];
    for(auto &i:a) cin >> i;
    int dp[N+1][MAX+1];
    int ans = INT_MAX;
    for(int i = 0; i <= N; ++i)
    {
        for(int j = 0; j <= MAX; ++j)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            } else if(a[i-1]<=j)
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i-1]]+a[i-1]);
            } else
            {
                dp[i][j] = dp[i][j-1];
            }
            if(dp[i][j] == B)
            {
                cout << dp[i][j];
                return 0;
            } else if(dp[i][j] > B && dp[i][j] < ans)
            {
                ans = dp[i][j];
            }
        }
    }
    if(ans == INT_MAX)
    {
        ans = dp[N][MAX];
    }
    cout << ans;
    return 0;
}