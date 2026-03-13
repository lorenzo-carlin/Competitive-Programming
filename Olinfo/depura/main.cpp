#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int k, r; cin >> k >> r;
    vector<ll> dp(2001, INF);
    for(int i = 0, a; i < k; i++)
    {
        cin >> a; a--;
        dp[a] = 0;
    }
    vector<vector<int>> adj(2001);
    for(int i = 0, a, n; i < r; i++)
    {
        cin >> a >> n; a--;
        for(int j = 0, b; j < n; j++)
        {
            cin >> b; b--;
            adj[a].push_back(b);
        }
    }

    int cnt = 0;
    auto solve = [&] (auto solve, int v) -> int
    {
        if(dp[v] == 0) return dp[v];
        else
        {
            ll mx = 0;
            for(int u: adj[v])
            {
                solve(solve, u);
                mx = max(mx, dp[u]);
            }
            cnt++;
            
            return dp[v] = mx;
        }
    };

    solve(solve, 0);

    if(dp[0] == INF) cout << -1 << "\n";
    else cout << cnt << "\n";
}

