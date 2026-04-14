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
		cin >> a >> b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	double ans = 0.0;
	
	auto dfs = [&] (auto dfs, int v, int p, double prob, int dep) -> void
	{
		int children = 0;
		for(int u: adj[v])
		{
			if(u == p) continue;
			children++;
		}

		if(children == 0)
		{
			ans += prob*dep;
			return;
		}

		for(int u: adj[v])
		{
			if(u == p) continue;
			dfs(dfs, u, v, prob / children, dep+1);
		}
	};
	dfs(dfs, 0, -1, 1.0, 0);

	cout << fixed << setprecision(10) << ans << "\n";
}
