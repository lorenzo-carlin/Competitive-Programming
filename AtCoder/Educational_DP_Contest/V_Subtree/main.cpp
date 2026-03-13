#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m; cin >> n >> m;
	vector<vector<int>> edges(n);
	vector<vector<int>> adj(n);
	vector<int> pos(n, -1);
	for(int i = 0, a, b; i < n-1; ++i)
	{
		cin >> a >> b; a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	// calcolo dp[i] := nr di modi di colorare il subtree di i rispettando le macchie di colore nero
	vector<ll> dp(n);
	vector<int> par(n, -1);
	auto dfs = [&] (auto dfs, int v, int p) -> void
	{
		dp[v] = 1;

		for(int u: edges[v])
		{
			if(u == p) continue;
			adj[v].push_back(u);
			pos[u] = adj[v].size()-1;
			par[u] = v;
			dfs(dfs, u, v);
			dp[v] *= dp[u];
			dp[v] %= m;
		}

		dp[v]++;
		dp[v] %= m;
	};
	dfs(dfs, 0, -1);

	// calcolo prefissi e suffissi dei valori di dp[] di siblings
	vector<deque<ll>> pre(n), suf(n);
	for(int i = 0; i < n; ++i)
	{
		pre[i].push_back(1);
		for(int u = 0; u < adj[i].size(); u++)
		{
			pre[i].push_back(pre[i].back()*dp[adj[i][u]] % m);
		}

		suf[i].push_front(1);
		for(int u = adj[i].size()-1; u >= 0; u--)
		{
			suf[i].push_front(suf[i].front()*dp[adj[i][u]] % m);
		}
	}

	// calcolo up[i] := nr di modi di colorare l'albero, tolto il subtree di i, in modo che par[i] sia nero oppure che non ci sia nessuno nodo nero
	
	vector<ll> up(n, 1);	
	auto dfs1 = [&] (auto dfs1, int v, int p) -> void
	{
		for(int u: adj[v])
		{
			if(u == p) continue;
			int x = pos[u];
			up[u] *= up[v];
			up[u] %= m;
			up[u] *= pre[v][x];
			up[u] %= m;
			up[u] *= suf[v][x+1];
			up[u] %= m;
			up[u]++;
			up[u] %= m;
			dfs1(dfs1, u, v);
		}
	};
	dfs1(dfs1, 0, -1);

	cout << (dp[0] + m - 1) % m << "\n";
	for(int i = 1; i < n; ++i)
	{
		cout << (((dp[i]+m-1)%m)*up[i] % m) << "\n";
	}

}
