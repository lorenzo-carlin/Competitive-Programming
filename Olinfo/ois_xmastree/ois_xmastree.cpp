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
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> a(n);
	for(int &i: a) cin >> i;

	ll dp[n][2];
	function<void(int,int)> dfs = [&] (int v, int p)
	{
		vector<int> figli_spenti;
		ll sum = 0;
		for(int u: adj[v])
		{
			if(u == p) continue;
			dfs(u, v);
			figli_spenti.push_back(dp[u][0]);
			sum += dp[u][0];
		}

		sort(rbegin(figli_spenti), rend(figli_spenti));

		if(figli_spenti.size() & 1)
		{
			ll cum = 0;
			dp[v][1] = cum;
			dp[v][0] = -1e18;
			for(int i = 0; i < figli_spenti.size(); ++i)
			{
				cum += figli_spenti[i];
				if(i & 1)
				{
					dp[v][1] = max(dp[v][1], cum);
				} else
				{
					dp[v][0] = max(dp[v][0], cum + a[v]);
				}
			}
		} else
		{
			ll cum = 0;
			dp[v][0] = cum + a[v];
			dp[v][1] = (figli_spenti.size() == 0) ? (0) : (-1e18);
			for(int i = 0; i < figli_spenti.size(); ++i)
			{
				cum += figli_spenti[i];
				if(i & 1)
				{
					dp[v][0] = max(dp[v][0], cum + a[v]);
				} else
				{
					dp[v][1] = max(dp[v][1], cum);
				}
			}
		}
	};

	dfs(0, -1);

	// for(int i = 0; i < n; ++i) cout << dp[i][0] << " ";
	// cout << "\n";
	// for(int i = 0; i < n; ++i) cout << dp[i][1] << " ";
	// cout << "\n";

	cout << max(dp[0][0], dp[0][1]) << "\n";
}
