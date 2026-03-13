#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	int n, m; cin >> n >> m;
	vector<array<int,2>> e(m);
	vector<vector<int>> adj(n);
	vector<vector<ll>> c(n, vector<ll> (n, 0));
	for(int i = 0, a, b; i < m; ++i)
	{
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		c[a][b]++;
		c[b][a]++;
		e[i] = {a, b};
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


	auto max_flow = [&] (int src, int snk) -> ll
	{
		ll flow = 0;
		ll new_f;
		while(new_f = bfs(src, snk))
		{
			flow += new_f;
			int ind = snk;
			while(ind != src)
			{
				int prv = par[ind];
				c[prv][ind] -= new_f;
				c[ind][prv] += new_f;
				ind = prv;
			}
		}
		return flow;
	};

	cout << max_flow(0, n-1) << "\n";
	
	vector<bool> vis(n, false);
	queue<int> q;
	q.push(0);
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		if(vis[v]) continue;
		vis[v] = true;

		for(int u: adj[v])
		{
			if(vis[u] || c[v][u] == 0) continue;
			else q.push(u);
		}
	}

	for(int i = 0; i < m; ++i)
	{
		if((vis[e[i][0]] && (!vis[e[i][1]])) || ((!vis[e[i][0]]) && vis[e[i][1]]))
			cout << e[i][0]+1 << " " << e[i][1]+1 << "\n";
	}
}
