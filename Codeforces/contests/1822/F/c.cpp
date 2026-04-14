#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n, k, c;
	cin >> n >> k >> c;

	vector<vector<int>> adj(n);
	for(int i = 0, a, b; i < n-1; i++)
	{
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	// profondità di ciascun nodo
	vector<ll> depth(n, 0);
	// mx[v].first = massima distanza in subtree v
	// mx[v].second = seconda massima
	vector<pair<ll,ll>> mx(n, {0, 0});
	// best[v] = figlio che contribuisce alla massima distanza (down1)
	vector<int> best(n, -1);

	// DFS per calcolare depth, mx1 e mx2
	auto dfs1 = [&] (auto self, int v, int p) -> void {
		for(int u : adj[v])
		{
			if(u == p) continue;
			depth[u] = depth[v] + 1;
			self(self, u, v);
			ll d = mx[u].first + 1;
			if(d > mx[v].first)
			{
				mx[v].second = mx[v].first;
				mx[v].first = d;
				best[v] = u;
			}
			else if(d > mx[v].second)
			{
				mx[v].second = d;
			}
		}
	};

	// DFS per calcolare up[v]
	vector<ll> up(n, 0);
	auto dfs2 = [&] (auto self, int v, int p) -> void {
		for(int u : adj[v])
		{
			if(u == p) continue;
			if(best[v] == u)
				up[u] = max(up[v] + 1, mx[v].second + 1);
			else
				up[u] = max(up[v] + 1, mx[v].first + 1);
			self(self, u, v);
		}
	};

	dfs1(dfs1, 0, -1);
	dfs2(dfs2, 0, -1);

	// calcolo il massimo profitto
	ll ans = 0;
	for(int i = 0; i < n; ++i)
	{
		ll dist = max(mx[i].first, up[i]);
		ans = max(ans, k * dist - c * depth[i]);
	}

	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();
}

