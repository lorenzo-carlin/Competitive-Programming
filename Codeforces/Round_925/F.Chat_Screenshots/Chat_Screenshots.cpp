#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int INF = 1e9;

void solve()
{
	int n, m; cin >> n >> m;
	vector<set<int>> adj(n+1);
	for(int i = 0; i < m; ++i)
	{
		vector<int> v(n);
		for(int j = 0; j < n; ++j) cin >> v[j];
		for(int j = 1; j < n-1; ++j)  adj[v[j]].insert(v[j+1]);
	}

	vector<int> vis(n+1, 0);

	bool cond = false;
	auto dfs = [&](auto self, int n) -> void
	{
		if(cond) return;
		vis[n] = 1;
		for(int v: adj[n])
		{
			if(vis[v] == 1) cond = true;
			if(cond) return;
			if(vis[v] == 0) self(self, v);
			if(cond) return;
		}
		if(cond) return;
		vis[n] = 2;
	};

	for(int i = 1; i <= n; ++i)
	{
		if(!cond) dfs(dfs,i);
	}

	if(cond) cout << "NO\n";
	else cout << "YES\n";
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}

