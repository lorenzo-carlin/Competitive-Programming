#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 505;
constexpr ll INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    ll a[n][m], c[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> c[i][j];

    ll dp[n][m];
    ll mx = -INF;
    for(int k = 1; k <= 500; k++)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                dp[i][j] = -INF;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 && j == 0) {}
                else if(i == 0)
                    dp[i][j] = dp[i][j-1];
                else if(j == 0)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

                if(dp[i][j] != -INF)
                    dp[i][j] += a[i][j];
                if(c[i][j] == k)
                {
                    dp[i][j] = max(dp[i][j], a[i][j]);
                    mx = max(mx, dp[i][j]);
                }

            }
        }

    }

    cout << mx << "\n";
}
