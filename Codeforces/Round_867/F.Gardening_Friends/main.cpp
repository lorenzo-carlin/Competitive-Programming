#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n, k, c; cin >> n >> k >> c;
	vector<vector<int>> adj(n);
	for(int i = 0, a, b; i < n-1; ++i)
	{
		cin >> a >> b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<ll> depth(n, -1);
    vector<pair<ll,int>> mx1(n, {0, -1}), mx2(n, {0, -1});
	vector<ll> up(n, -1);
	depth[0] = 0;

	auto dfs1 = [&] (auto dfs1, int v, int p) -> void
	{
		for(int u: adj[v])
		{
			if(u == p) continue;

			depth[u] = depth[v]+1;
			dfs1(dfs1, u, v);

			if(mx1[u].first+1 > mx1[v].first)
			{
				swap(mx1[v], mx2[v]);
				mx1[v].first = mx1[u].first+1;
				mx1[v].second = u;
			} else if(mx1[u].first+1 > mx2[v].first)
			{
				mx2[v].first = mx1[u].first+1;
				mx2[v].second = u;
			}
		}

		for(int u: adj[v])
		{
			if(u == p) continue;
			up[u] = up[v]+1;			
			if(mx1[v].second == u) up[u] = max(up[u], mx2[v].first+1);
			else up[u] = max(up[u], mx1[v].first+1);
		}
	};

	dfs1(dfs1, 0, -1);

	ll mx = 0;
	for(int i = 0; i < n; ++i)
	{
		mx = max(mx, (ll)k*max(mx1[i].first,up[i])-c*depth[i]);
	}

	cout << mx << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
