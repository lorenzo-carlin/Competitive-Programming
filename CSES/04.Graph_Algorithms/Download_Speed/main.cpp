#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n);
	vector<vector<ll>> c(n, vector<ll> (n));
	for(int i = 0, a, b, w; i < m; ++i)
	{
		cin >> a >> b >> w; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		c[a][b] += w;
	}
	for(int i = 0; i < n; ++i)
	{
		sort(begin(adj[i]), end(adj[i]));
		adj[i].erase(unique(begin(adj[i]), end(adj[i])), end(adj[i]));
	}

	vector<int> par(n);
	auto bfs = [&] (int src, int snk) -> ll
	{
		fill(begin(par), end(par), -1);
		queue<array<ll,2>> q;
		q.push({src, (ll)1e15});
		while(!q.empty())
		{
			ll v = q.front()[0];
			ll f = q.front()[1];
			q.pop();

			for(int u: adj[v])
			{
				if(par[u] != -1 || c[v][u] == 0)
					continue;
				par[u] = v;
				ll new_f = min(f, c[v][u]);
				if(u == snk)
					return new_f;
				else
					q.push({u, new_f});
			}
		}
		return 0;
	};

	auto maxflow = [&] (int src, int snk) -> ll
	{
		ll flow = 0;
		ll new_flow;
		while(new_flow = bfs(src, snk))
		{
			flow += new_flow;
			int ind = snk;
			while(ind != src)
			{
				int prv = par[ind];
				c[prv][ind] -= new_flow;
				c[ind][prv] += new_flow;
				ind = prv;
			}
		}
		return flow;
	};

	cout << maxflow(0, n-1) << "\n";
}
