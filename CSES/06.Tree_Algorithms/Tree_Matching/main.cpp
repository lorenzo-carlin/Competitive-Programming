#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 2e5 + 5;
vector<vector<int>> adj(MAXN);
vector<array<int,2>> dp(MAXN);

void dfs(int n, int p)
{
    dp[n][0] = dp[n][1] = 0;
    for(int v: adj[n])
    {
        if(v == p) continue;
        dfs(v, n);
        dp[n][0] += max(dp[v][0], dp[v][1]);
    }
    for(int v: adj[n])
    {
        if(v == p) continue;
        dp[n][1] = max(dp[n][1], dp[v][0] + 1 + dp[n][0] - max(dp[v][0], dp[v][1]));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for(int i = 0, a, b; i < n-1; ++i)
    {
        cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1);
    int ans = max(dp[0][0], dp[0][1]);
    cout << ans << "\n";
}