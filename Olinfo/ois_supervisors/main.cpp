#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;
    vector<ll> s(n);
    for(ll &i: s) cin >> i;
    
    vector<vector<int>> adj(n);
    for(int i = 1, a; i < n; i++)
    {
        cin >> a;
        adj[a].push_back(i);
    }

    vector<vector<ll>> dp(n, vector<ll> (k+1, -INF));
    vector<int> sz(n, 0);
    vector<ll> tmp;

    auto dfs = [&] (auto dfs, int v) -> void
    {
        sz[v] = 1;
        dp[v][0] = 0;

        for(int u: adj[v])
        {
            dfs(dfs, u);
            tmp = dp[v];

            for(int i = 0; i <= min(k, sz[v]); i++)
            {
                if(tmp[i] == -INF) continue;
                for(int j = 0; j + i <= k && j <= sz[u]; j++)
                {
                    if(dp[u][j] == -INF) continue;
                    dp[v][i+j] = max(dp[v][i+j], tmp[i]+dp[u][j] + s[v]*i*j);
                }
            }

            sz[v] += sz[u];
        }

        for(int i = k-1; i >= 0; i--)
        {
            if(dp[v][i] == -INF) continue;
            dp[v][i+1] = max(dp[v][i+1], dp[v][i] + s[v]*i);
        }
    };

    dfs(dfs, 0);

    cout << dp[0][k] << "\n";
}
