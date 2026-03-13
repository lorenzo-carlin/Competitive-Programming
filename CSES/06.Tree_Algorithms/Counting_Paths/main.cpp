#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int LOG = 20;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n);
	for(int i = 0, a, b; i < n-1; ++i)
	{
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> dep(n, 0);
	vector<vector<int>> up (n, vector<int> (LOG, -1));

	auto dfs = [&] (auto dfs, int v, int p) -> void
	{
		for(int u: adj[v])
		{
			if(u == p) continue;
			dep[u] = dep[v]+1;
			dfs(dfs, u, v);
			up[u][0] = v;
		}
	};

	dfs(dfs, 0, -1);

	for(int j = 1; j < LOG; j++)
	{
		for(int i = 0; i < n; i++)
		{
			if(up[i][j-1] == -1)
			{
				up[i][j] = -1;
			} else
			{
				up[i][j] = up[up[i][j-1]][j-1];
			}
		}
	}

	auto binary_lift = [&] (int v, int k) -> int
	{
		for(int j = 0; j < LOG; j++)
		{
			if(v == -1)
				break;
			if(k & (1 << j))
				v = up[v][j];
		}
		return v;
	};

	auto lca = [&] (int a, int b) -> int
	{
		if(dep[a] > dep[b])
			swap(a, b);
		b = binary_lift(b, dep[b]-dep[a]);
		if(a == b)
			return a;
		for(int j = LOG-1; j >= 0; j--)
		{
			if(up[a][j] != up[b][j])
			{
				a = up[a][j];
				b = up[b][j];
			}
		}
		return up[a][0];
	};

	vector<int> cnt(n, 0);
	for(int i = 0, a, b; i < m; ++i)
	{
		cin >> a >> b; a--; b--;
		cnt[a]++;
		cnt[b]++;
		int l = lca(a, b);
		cnt[l]--;
		if(up[l][0] != -1)
			cnt[up[l][0]]--;
	}

	vector<int> sol(n, 0);
	auto ans = [&] (auto ans, int v, int p) -> void
	{
		sol[v] += cnt[v];
		for(int u: adj[v])
		{
			if(u == p) continue;
			ans(ans, u, v);
			sol[v] += sol[u];
		}
	};

	ans(ans, 0, -1);

	for(int el: sol) cout << el << " ";
	cout << "\n";
}
