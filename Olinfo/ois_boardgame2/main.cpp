#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	vector<vector<pair<int,int>>> adj(n);
	for(int i = 0, a, b, c; i < m; i++)
	{
		cin >> a >> b >> c;
		a--; b--;
		adj[a].push_back({b, c});
	}

	vector<pair<bool,ll>> dp(n);
	vector<bool> memo(n, false);
	auto dfs = [&] (auto dfs, int v) -> pair<bool,ll>
	{
		if(memo[v]) return dp[v];
		memo[v] = true;

		ll mx = 0, mn = 1e18;
		for(auto [u, w]: adj[v])
		{
			auto tmp = dfs(dfs, u);
			if(tmp.first == true)
			{
				mx = max(mx, tmp.second);
			} else
			{
				mn = min(mn, tmp.second+w);
			}
		}

		if(mn != 1e18)
		{
			return dp[v] = {true, mn};
		} else
		{
			return dp[v] = {false, mx};
		}
	};

	dfs(dfs, 0);

	if(dp[0].first == true)
	{
		cout << "Alice\n";
	} else
	{
		cout << "Bob\n";
	}
	cout << dp[0].second << "\n";
}
