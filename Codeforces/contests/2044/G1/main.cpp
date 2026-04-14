#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<int> nxt(n);
	for(int i = 0, a; i < n; ++i)
	{
		cin >> a; a--;
		nxt[i] = a;
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

	vector<int> ans(n, -1);

	auto dfs = [&] (auto dfs, int v) -> int
	{
		if(ans[v] != -1) return ans[v];
		if(cycle[v]) return ans[v] = 0;
		return ans[v] = dfs(dfs, nxt[v]) + 1;
	};

	
	for(int i = 0; i < n; ++i)
	{
		if(col[i] == 0)
		{
			find_cycle(find_cycle, i);
		}
	}

	for(int i = 0; i < n; ++i)
	{
		if(ans[i] == -1)
		{
			dfs(dfs, i);
		}
	}

	int sol = -1;
	for(int i = 0; i < n; ++i)
	{
		sol = max(sol, ans[i]);
	}

	cout << sol+2 << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
