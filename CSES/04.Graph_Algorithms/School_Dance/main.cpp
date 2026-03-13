#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int INF = 1e9;

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	int n, m, k; cin >> n >> m >> k;
	// da 1 a n sono i maschi
	// da n+1 a n+m sonon le femmine
	// 0 è la sorgente
	// n+m+1 è il pozzo
	vector<vector<int>> adj(n+m+2);
	vector<vector<int>> c(n+m+2, vector<int> (n+m+2, 0));
	for(int i = 0, a, b; i < k; ++i)
	{
		cin >> a >> b;
		adj[a].push_back(n+b);
		adj[n+b].push_back(a);
		c[a][n+b] = 1;
		//c[n+b][a] = 1;
	}

	for(int i = 1; i <= n; ++i)
	{
		adj[0].push_back(i);
		adj[i].push_back(0);
		c[0][i] = 1;
		//c[i][0] = 1;
	}

	for(int i = 1; i <= m; ++i)
	{
		adj[n+i].push_back(n+m+1);
		adj[n+m+1].push_back(n+i);
		c[n+i][n+m+1] = 1;
		//c[n+m+1][n+i] = 1;
	}

	vector<int> par(n+m+2, -1);

	auto bfs = [&] (int st, int fn) -> int
	{
		// ritorna il valore minimo sul cammino di lunghezza minima
		queue<array<int,2>> q;
		q.push({st, INF});
		fill(begin(par), end(par), -1);
		while(!q.empty())
		{
			int v = q.front()[0];
			int d = q.front()[1];
			q.pop();

			for(int u: adj[v])
			{
				if(par[u] != -1 || c[v][u] == 0)
					continue;
				par[u] = v;
				int new_f = min(d, c[v][u]);
				if(u == fn)
					return new_f;
				q.push({u, new_f});
			}

		}
		return 0;
	};

	auto max_flow = [&] (int st, int fn) -> int
	{
		int flow = 0;
		int new_flow;
		while(new_flow = bfs(st, fn))
		{
			flow += new_flow;
			// aggiorno i pesi
			int ind = fn;
			while(ind != st)
			{
				int prv = par[ind];
				c[prv][ind] -= new_flow;
				c[ind][prv] += new_flow;
				ind = prv;
			}
		}
		return flow;
	};

	int ans = max_flow(0, n+m+1);
	cout << ans << "\n";

	for(int i = 1; i <= n; ++i)
	{
		for(int u = n+1; u <= n+m; ++u)
		{
			if(c[i][u] == 0 && c[u][i] == 1)
			{
				cout << i << " " << u-n << "\n";
			}
		}
	}

}
