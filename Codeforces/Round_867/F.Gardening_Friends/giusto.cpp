#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	// leggo l'albero
	int n, k, c; cin >> n >> k >> c;
	vector<vector<int>> adj(n);
	for(int i = 0, a, b; i < n-1; i++)
	{
		cin >> a >> b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	// calcolo la depth di ogni nodo
	vector<ll> depth(n, 0);
	auto find_depth = [&] (auto find_depth, int v, int p) -> void
	{
		for(int u: adj[v])
		{
			if(u == p) continue;
			depth[u] = depth[v]+1;
			find_depth(find_depth, u, v);
		}
	};

	// calcolo mx1
	vector<pair<ll,ll>> mx1(n, {0, -1});
	auto find_mx1 = [&] (auto find_mx1, int v, int p) -> void
	{
		for(int u: adj[v])
		{
			if(u == p) continue;
			find_mx1(find_mx1, u, v);
			if(mx1[u].first+1 > mx1[v].first)
			{
				mx1[v].first = mx1[u].first+1;
				mx1[v].second = u;
			}
		}
	};

	// calcolo mx2
	vector<pair<ll,ll>> mx2(n, {0, -1});
	auto find_mx2 = [&] (auto find_mx2, int v, int p) -> void
	{
		for(int u: adj[v])
		{
			if(u == p || mx1[v].second == u) continue;
			find_mx2(find_mx2, u, v);
			if(mx2[u].first+1 > mx2[v].first)
			{
				mx2[v].first = mx2[u].first+1;
				mx2[v].second = u;
			}
		}
	};

	// calcolo up
	vector<ll> up(n, 0);
	auto find_up = [&] (auto find_up, int v, int p) -> void
	{
		for(int u: adj[v])
		{
			if(u == p) continue;
			up[u] = up[v]+1;
			if(mx1[v].second == u) up[u] = max(up[u], mx2[v].first+1);
			else up[u] = max(up[u], mx1[v].first+1);
		}
	};


	find_depth(find_depth, 0, -1);
	find_mx1(find_mx1, 0, -1);
	find_mx2(find_mx2, 0, -1);
	find_up(find_up, 0, -1);

	// cerco la risposta
	ll ans = 0;
	for(int i = 0; i < n; ++i)
	{
		ans = (ll) max(ans, (ll)k*max(up[i], mx1[i].first) - (ll)c*depth[i]);
	}

	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
