#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<vector<array<int,2>>> adj(n);
	vector<array<int,2>> edges(n);
	vector<int> col(n, 0); // 1 o 2
	vector<int> occ(n, 0);
	vector<int> vis(n, 0);
	
	for(int i = 0, a, b; i < n; ++i)
	{
		cin >> a >> b;
		a--; b--;
		adj[a].push_back({b, i});
		adj[b].push_back({a, i});
		edges[i] = {a, b};
		occ[a]++;
		occ[b]++;
	}

	for(int i = 0; i < n; ++i)
	{
		if(occ[i] != 2)
		{
			cout << "NO\n";
			return;
		}
	}

	auto dfs = [&] (auto dfs, int v, int last) -> void
	{
		vis[v]++;
		if(col[adj[v][0][1]] == 0)
		{
			col[adj[v][0][1]] = 3-last;
			dfs(dfs, adj[v][0][0], 3-last);
		} else if(col[adj[v][1][1]] == 0)
		{
			col[adj[v][1][1]] = 3-last;
			dfs(dfs, adj[v][1][0], 3-last);
		}
	};

	for(int i = 0; i < n; ++i)
	{
		if(vis[i] < 2)
		{
			dfs(dfs, i, 1);
		}
	}

	for(int i = 0; i < n; ++i)
	{
		if(col[adj[i][0][1]] == col[adj[i][1][1]])
		{
			cout << "NO\n";
			return;
		}
	}
	
	cout << "YES\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
