#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<vector<int>> adj(n);
    vector<int> b(n);
    for(int i = 0, x, y; i < n; i++)
    {
        cin >> x >> y;
        b[i] = x;
        if(y == -1) continue;
        adj[y].push_back(i);
    }

    vector<int> dp(n, 0);
    auto dfs = [&] (auto dfs, int v) -> void
    {
        int sum = 0;
        for(int u: adj[v])
        {
            dfs(dfs, u);
            sum += dp[u];
        }
        dp[v] = max(b[v], sum);
    };

    dfs(dfs, 0);
    cout << dp[0] << "\n";
}
