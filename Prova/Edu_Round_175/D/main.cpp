#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 998244353;

void solve()
{
	int n; cin >> n;
	vector<vector<int>> adj(n);
	for(int i = 1, a; i < n; ++i)
	{
		cin >> a; a--;
		adj[a].push_back(i);
	}

	vector<vector<int>> h(n+1);
	vector<ll> sum(n+1, 0);
	auto high = [&] (auto high, int v, int p, int d) -> void
	{
		h[d].push_back(v);
		for(int u: adj[v])
		{
			high(high, u, v, d+1);
		}
	};
	high(high, 0, -1, 0);

	vector<ll> dp(n, 0);
	for(int i = n-1; i > 0; i--)
	{
		for(int v: h[i])
		{
			dp[v] = 1;
			dp[v] += sum[i+1];
			dp[v] %= mod;
			for(int u: adj[v])
			{
				dp[v] -= dp[u];
				dp[v] += mod;
				dp[v] %= mod;
			}
			sum[i] += dp[v];
			sum[i] %= mod;
		}
	}

	ll ans = 1 + sum[1];
	ans %= mod;

	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
