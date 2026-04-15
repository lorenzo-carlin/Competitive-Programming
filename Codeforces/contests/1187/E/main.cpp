#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<vector<int>> adj(n);
	for(int i = 0, a, b; i < n-1; ++i)
	{
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	ll ans = 0;

	vector<ll> dp(n);
	vector<int> sz(n);
	auto dfs = [&](auto dfs, int v, int p) -> void
	{
		sz[v] = 1;
		dp[v] = 0;

		for(int u: adj[v])
		{
			if(u == p) continue;
			dfs(dfs, u, v);
			sz[v] += sz[u];
			dp[v] += dp[u];
		}
		
		dp[v] += sz[v];
	};

	dfs(dfs, 0, -1);

	ans = dp[0];
	auto reroot = [&](auto reroot, int v, int p) -> void
	{
		for(int u: adj[v])
		{
			if(u == p) continue;
			// tolgo u da v
			sz[v] -= sz[u];
			dp[v] -= (dp[u] + sz[u]);
			// aggiungo v a u
			sz[u] += sz[v];
			dp[u] += (dp[v] + sz[v]);
			ans = max(ans, dp[u]);
			// ricorsiva
			reroot(reroot, u, v);
			// tolgo v a u
			sz[u] -= sz[v];
			dp[u] -= (dp[v] + sz[v]);
			// aggiungo u a v
			sz[v] += sz[u];
			dp[v] += (dp[u] + sz[u]);
		}
	};

	reroot(reroot, 0, -1);

	cout << ans << "\n";
}
