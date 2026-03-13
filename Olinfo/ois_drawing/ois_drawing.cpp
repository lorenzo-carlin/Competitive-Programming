#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, e; cin >> n >> m >> e;
	// i numeri da 0 a n-1 sono quelli della riga sopra
	// i numeri da n a m-1 sono quelli della riga sotto
	vector<vector<int>> adj(n+m);
	for(int i = 0, a, b; i < e; ++i)
	{
		cin >> a >> b;
		b += n;
		adj[a].push_back(b);
		if(a == b) continue;
		adj[b].push_back(a);
	}
	vector<int> deg(n+m);
	for(int i = 0; i < n+m; ++i)
	{
		deg[i] = adj[i].size();
	}

	for(int i = 0; i < n+m; ++i)
	{
		sort(begin(adj[i]), end(adj[i]), [&](int a, int b)
		{
			return deg[a] < deg[b];
		});
	}

	vector<int> A, B;

	vector<bool> vis(n+m, false);
	vector<bool> built(n+m, false);
	bool valid = true;
	auto check_comp = [&] (auto check_comp, int v, int p) -> void
	{
		// non ci devono essere cicli
		// ogni nodo deve avere al massimo 2 vicini con grado > 1
		vis[v] = true;
		int nodi_speciali = 0;
		for(int u: adj[v])
		{
			if(u != -1 && deg[u] > 1) nodi_speciali++;
			if(u == p) continue;
			if(vis[u]) valid = false;
			else check_comp(check_comp, u, v);
		}
		if(nodi_speciali > 2) valid = false;
	};

	auto find_start = [&] (auto find_start, int v, int p) -> int
	{
		// il nodo di start deve avere al massimo un vicino con grado > 1
		if(vis[v]) return -1;
		vis[v] = true;
		int nodi_speciali = 0;
		for(int u: adj[v])
		{
			if(u != -1 && deg[u] > 1) nodi_speciali++;
			if(u == p) continue;
			int tmp = find_start(find_start, u, v);
			if(tmp != -1) return tmp;
		}
		if(nodi_speciali <= 1) return v;
		return -1;
	};

	auto print = [&] (int val)
	{
		if(val < n) A.push_back(val);
		else B.push_back(val-n);
	};

	auto build = [&] (auto build, int v, int p) -> void
	{
		print(v);
		built[v] = true;
		for(int u: adj[v])
		{
			if(u == p) continue;
			if(deg[u] <= 1)
			{
				built[u] = true;
				print(u);
			} else
			{
				build(build, u, v);
			}
		}
	};

	for(int i = 0; i < n+m; ++i)
	{
		if(built[i]) continue;
		// controllo la validità della componente
		fill(begin(vis), end(vis), false);
		check_comp(check_comp, i, -1);
		if(!valid)
		{
			cout << -1 << "\n";
			return 0;
		}
		// cerco il punto di start
		fill(begin(vis), end(vis), false);
		int st = find_start(find_start, i, -1);
		if(st == -1)
		{
			cout << -1 << "\n";
			return 0;
		}
		// buildo
		build(build, st, -1);
	}

	for(int el: A) cout << el << " ";
	cout << "\n";
	for(int el: B) cout << el << " ";
	cout << "\n";
}
