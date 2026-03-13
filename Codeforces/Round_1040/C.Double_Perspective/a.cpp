#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 8000;

void solve()
{
	int n; cin >> n;
	map<pair<int,int>,int> idx; // indici degli archi
	int cnt = 1;
	vector<vector<int>> adj(MAXN);
	vector<bool> vis(MAXN, false);
	for(int i = 0, a, b; i < n; ++i)
	{
		cin >> a >> b;
		idx[{a,b}] = cnt++;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> ans;

	auto dfs = [&] (auto dfs, int v) -> void
	{
		vis[v] = true;
		for(int u: adj[v])
		{
			if(vis[u]) continue;
			ans.push_back(idx[{min(v,u),max(v,u)}]);
			dfs(dfs, u);
		}
	};

	for(int i = 0; i < MAXN; ++i)
	{
		if(!vis[i]) dfs(dfs, i);
	}

	cout << ans.size() << "\n";
	for(int el: ans) cout << el << " ";
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
