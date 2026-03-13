#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	string s; cin >> s;
	vector<vector<int>> adj(n);
	for(int i = 0, a, b; i < m; ++i)
	{
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
	}

	// ordinamento topologico
	vector<int> topo, col(n, 0);
	bool impossible = false;
	vector<vector<int>> G(n);	// grafo effettivo

	auto toposort = [&] (auto toposort, int v) -> void
	{
		col[v] = 1;
		for(int u: adj[v])
		{
			if(col[u] == 1) impossible = true;			
			if(col[u] == 0)
			{
				toposort(toposort, u);
				G[v].push_back(u);
			}
		}
		topo.push_back(v);
		col[v] = 2;
	};
	
	for(int i = 0; i < n; ++i)
	{
		if(col[i] > 0) continue;
		toposort(toposort, i);
	}

	reverse(begin(topo), end(topo));

	// processo i nodi in ordine
	vector<vector<int>> f(n, vector<int> (26, 0));
	// f[i][j] := occorrenze della lettera j nel path fino a i (incluso)

	int mx = 0;
	for(int i = 0; i < n; ++i)
	{
		int idx = topo[i];
		f[idx][s[idx]-'a']++;

		for(int u: G[idx])
		{
			for(int j = 0; j < 26; ++j)
			{
				f[u][j] += f[idx][j];
			}
		}
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < 26; ++j)
		{
			mx = max(mx, f[i][j]);
		}
	}

	if(impossible) cout << -1 << "\n";
	else cout << mx << "\n";
}
