#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<vector<int>> adj(n);
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			char c; cin >> c;
			if(c == '1')
			{
				adj[j].push_back(i);
			}
		}
	}

	vector<set<int>> memo(n);
	for(int i = 0; i < n; ++i) memo[i].insert(i);
	vector<bool> vis(n, false);

	auto dfs = [&] (auto dfs, int v) -> void
	{
		vis[v] = true;

		for(int u: adj[v])
		{
			if(!vis[u]) dfs(dfs, u);
			for(int el: memo[u]) memo[v].insert(el);
		}
	};

	for(int i = 0; i < n; ++i)
	{
		if(!vis[i]) dfs(dfs, i);
	}

	for(int i = 0; i < n; ++i)
	{
		cout << memo[i].size() << " ";
		for(int el: memo[i]) cout << el+1 << " ";
		cout << "\n";
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
