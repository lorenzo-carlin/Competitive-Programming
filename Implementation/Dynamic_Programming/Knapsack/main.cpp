/*
 * Knapsack (both recursive and iterative)
 * Solves the 0/1 Knapsack problem using dynamic programming to maximize
 * the total value within a given weight capacity.
 */


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, W;
const int MAXN = 105;
const int MAXW = 1e5+5;
ll p[MAXN];
ll w[MAXN];
ll memo[MAXN][MAXW];
bool vis[MAXN][MAXW];

ll solve(int ind, int curr)
{
    if(curr < 0) return -1e9;
    if(ind == N) return 0;
    if(curr == 0) return 0;
    
    if(vis[ind][curr]) return memo[ind][curr];
    vis[ind][curr] = true;

    return memo[ind][curr] = max(solve(ind+1, curr), solve(ind+1, curr-w[ind])+p[ind]);
}

int iterative() {
    int n, w; cin >> n >> w;

    vector<vector<ll>> dp(w+1, vector<ll>(n+1, 0));
    ll a[n], b[n];
    for(int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    
    ll sol = 0;
    for(int i = 1; i <= w; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
            if(i - b[j-1] >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i-b[j-1]][j-1]+a[j-1]);
            }
            sol = max(sol, dp[i][j]);
        }
    }
    return sol;
}

int main()
{
    cin >> N >> W;
    for(int i = 0; i < N; ++i) cin >> w[i] >> p[i];

    cout << solve(0, W) << "\n";
}
