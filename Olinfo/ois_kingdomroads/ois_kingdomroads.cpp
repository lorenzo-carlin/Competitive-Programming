#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU
{
	int n;
	vector<int> par;

	DSU() {}
	DSU(int _n)
	{
		n = _n;
		par.resize(n);
		iota(begin(par), end(par), 0);
	}

	int find(int a)
	{
		if(par[a] == a) return a;
		else return par[a] = find(par[a]);
	}

	bool merge(int a, int b)
	{
		int A = find(a);
		int B = find(b);
		
		if(A == B)
		{
			return false;
		} else
		{
			par[A] = B;
			return true;
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k; cin >> n >> m >> k;
	vector<vector<pair<int,int>>> adj(n);	// grafo senza archi speciali
	vector<array<int,3>> special, normal;
	map<int,int> mp;
	for(int i = 0, a, b, c; i < m; i++)
	{
		cin >> a >> b >> c;
		a--; b--;
		
		if(a == 0 || b == 0)
		{
			special.push_back({c, a, b});
			mp[a] = c;
			mp[b] = c;
		} else
		{
			normal.push_back({c, a, b});
			adj[a].push_back({b, c});
			adj[b].push_back({a, b});
		}
	}
	mp.erase(0);

	vector<vector<int>> componenti(n);
	vector<bool> vis(n, false);
	int idx = 0, nrcomponenti = 0;

	auto dfs = [&] (auto dfs, int v) -> void
	{
		vis[v] = true;
		if(mp.count(v)) componenti[idx].push_back(v);

		for(auto u: adj[v])
		{
			if(!vis[u.first])
			{
				dfs(dfs, u.first);
			}
		}
	};

	for(int i = 1; i < n; i++)
	{
		if(!vis[i])
		{
			dfs(dfs, i);
			nrcomponenti++;
			idx++;
		}
	}

	if(nrcomponenti > k)
	{
		cout << -1 << "\n";
		return 0;
	}

	DSU dsu = DSU(n);
	ll ans = 0;
	sort(begin(normal), end(normal));
	for(auto el: normal)
	{
		if(dsu.merge(el[1], el[2]))
		{
			ans += el[0];
		}
	}

	cout << ans << "\n";

	set<int> selected;
	for(int i = 0; i < n; i++)
	{
		if(componenti[i].empty()) continue;
		int mn = 1e9+5, mn_ind = -1;
		for(int el: componenti[i])
		{
			if(mp[el] < mn)
			{
				mn = mp[el];
				mn_ind = el;
			}
		}
		ans += mn;
		selected.insert(mn_ind);
	}

	int rem = k-nrcomponenti;
	sort(begin(special), end(special));
	for(auto el: special)
	{
		if(rem == 0) break;
		if(selected.count(el[1]) || selected.count(el[2])) continue;
		ans += el[0];
		rem--;
	}

	cout << ans << "\n";
}
