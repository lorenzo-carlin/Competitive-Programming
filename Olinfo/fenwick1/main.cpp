#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;

struct FenwickTree
{
	int n;
	vector<ll> bit;

	FenwickTree(int _n)
	{
		n = _n;
		bit.resize(n, 0);
	}

	void update(int ind, int delta)
	{
		while(ind < n)
		{
			bit[ind] += delta;
			ind = (ind | (ind+1));
		}
	}

	void range_update(int l, int r, int delta)
	{
		update(l, delta);
		update(r+1, -delta);
	}

	ll query(int ind)
	{
		ll res = 0;
		while(ind >= 0)
		{
			res += bit[ind];
			ind = ((ind & (ind+1))-1);
		}
		return res;
	}
};	

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, q; cin >> n >> q;
	vector<vector<int>> adj(n);
	vector<int> wages(n);
	cin >> wages[0];

	for(int i = 1, s; i < n; ++i)
	{
		cin >> wages[i] >> s;
		s--;
		adj[i].push_back(s);
		adj[s].push_back(i);
	}

	vector<int> in(n), out(n), sz(n, 0);
	int timer = 0;

	auto dfs = [&] (int v, int p, auto self) -> void
	{
		in[v] = timer++;
		for(int u: adj[v])
		{
			if(p == u) continue;
			self(u, v, self);
			sz[v] += (sz[u]+1);
		}
		out[v] = timer;
	};

	dfs(0, -1, dfs);

	FenwickTree fen = FenwickTree(n);

	for(int i = 0; i < q; ++i)
	{
		char type; cin >> type;
		if(type == 'p')
		{
			int a, b; cin >> a >> b;
			a--;
			fen.range_update(in[a]+1, out[a]-1, b);
		} else
		{
			int a; cin >> a;
			a--;
			cout << fen.query(in[a])+wages[a] << "\n";
		}
	}
}
