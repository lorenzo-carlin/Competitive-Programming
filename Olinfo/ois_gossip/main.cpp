#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU
{
	int n;
	vector<int> f;

	DSU() {}
	DSU(int _n) : n(_n)
	{
		f.resize(n);
		iota(begin(f), end(f), 0);
	}

	int find(int a)
	{
		return (f[a] == a) ? (a) : (f[a] = find(f[a]));
	}

	void merge(int a, int b)
	{
		int A = find(a);
		int B = find(b);

		f[A] = B;
	}

	bool same(int a, int b)
	{
		int A = find(a);
		int B = find(b);

		if(A == B) return true;
		else return false;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<vector<int>> adj(n);
	DSU dsu = DSU(n);
	for(int i = 0; i < n; ++i)
	{
		int a; cin >> a;
		adj[i].push_back(a);
		adj[a].push_back(i);
		dsu.merge(a, i);
	}

	vector<bool> vis(n, false);
	map<int,int> sz;
	vector<int> dist(n, 1e9);

	auto dfs = [&](auto self, int n, int p, int &mx) -> void
	{
		for(int i: adj[n])
		{
			if(i == p) continue;
			if(!vis[i])
			{
				dist[i] = dist[n]+1;
				mx = max(mx, dist[i]);
				vis[i] = true;
				self(self, i, n, mx);
			}
		}
	};

	for(int i = 0; i < n; ++i)
	{
		int p = dsu.find(i);
		if(!vis[p])
		{
			vis[p] = true;
			dist[p] = 0;
			int mx = 0;
			dfs(dfs, p, -1, mx);
			sz[p] = mx+1;
		}
	}

	int q; cin >> q;
	while(q--)
	{
		int a, b; cin >> a >> b;
		if(!dsu.same(a, b))
		{
			cout << -1 << " ";
		} else
		{
			int p = dsu.find(a);

			int op1 = abs(dist[a] - dist[b]);
			int op2 = sz[p] - op1;

			cout << min(op1, op2) << " ";
		}
	}
	cout << "\n";
}
