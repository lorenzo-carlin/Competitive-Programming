#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	int a, b; cin >> a >> b; a--; b--;
	vector<vector<int>> adj(n);
	for(int i = 0, c, d; i < n-1; ++i)
	{
		cin >> c >> d;
		c--; d--;
		adj[c].push_back(d);
		adj[d].push_back(c);
	}

	// trovo il numero di step prima che b raggiunga un nodo r
	stack<int> s;
	bool cond = false;
	auto dfs = [&] (auto dfs, int v, int p) -> void
	{
		s.push(v);

		if(v == a) cond = true;
		if(cond) return;

		for(int u: adj[v])
		{
			if(cond) return;
			if(u == p) continue;
			dfs(dfs, u, v);
		}

		if(cond) return;
		s.pop();
	};

	dfs(dfs, b, -1);
	vector<int> path;
	while(!s.empty())
	{
		path.push_back(s.top());
		s.pop();
	}
	reverse(begin(path), end(path));
	int step1 = path.size()/2;
	int root = path[step1];

	vector<int> d(n, 0);
	auto dp = [&] (auto dfs, int v, int p) -> void
	{
		for(int u: adj[v])
		{
			if(u == p) continue;
			dfs(dfs, u, v);
			d[v] += (d[u]+1);
		}
	};
	dp(dp, root, -1);

	vector<int> depth(n, 0);
	auto dep = [&] (auto dep, int v, int p) -> void
	{
		for(int u: adj[v])
		{
			if(u == p) continue;
			dep(dep, u, v);
			depth[v] = max(depth[v], depth[u]+1);
		}
	};
	dep(dep, root, -1);

	int step2 = 2*d[root]-depth[root];

	cout << step1+step2 << "\n";
}


int main()
{
	int t; cin >> t;
	while(t--) solve();
}
