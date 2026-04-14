#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<vector<int>> adj_rev(n);
	vector<int> nxt(n);
	for(int i = 0, a; i < n; ++i)
	{
		cin >> a; a--;
		nxt[i] = a;
		adj_rev[a].push_back(i);
	}

	vector<int> col(n, 0);
	vector<bool> cycle(n, false);

	auto find_cycle = [&] (auto find_cycle, int v) -> void
	{
		col[v] = 1;

		int u = nxt[v];
		if(col[u] == 1)
		{
			cycle[u] = true;
			int idx = nxt[u];
			while(idx != u)
			{
				cycle[idx] = true;
				idx = nxt[idx];
			}
		}
		if(col[u] == 0)
		{
			find_cycle(find_cycle, u);
		}

		col[v] = 2;
	};

	for(int i = 0; i < n; ++i)
	{
		if(col[i] == 0)
		{
			find_cycle(find_cycle, i);
		}
	}

	vector<int> dp(n, -1);

	auto dfs = [&] (auto dfs, int v) -> int
	{
		if(dp[v] != -1) return dp[v];

		int cnt = 0;

		for(int u: adj_rev[v])
		{
			if(cycle[u]) continue;
			if(cycle[v]) cnt = max(cnt, dfs(dfs, u));
			else cnt += dfs(dfs, u);
		}

		return dp[v] = cnt+1;
	};

	int mx = 0;
	for(int i = 0; i < n; ++i)
	{
		int t = dfs(dfs, i);
		if(cycle[i])
		{
			mx = max(mx, t);
		}
	}

	cout << mx+1 << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
