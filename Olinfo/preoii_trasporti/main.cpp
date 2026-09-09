#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;

constexpr int INF = 1e9;

struct Segment
{
	int n;
	vector<int> t;

	Segment() {}

	Segment(int _n, vector<int> a)
	{
		for(n = 1; n <= _n; n <<= 1);
		t.resize(2*n);
		for(int i = 0; i < _n; ++i) t[i+n] = a[i];
		for(int i = n-1; i > 0; i--) t[i] = max(t[i<<1], t[i<<1|1]);
	}

	void update(int p, int v)
	{
		for(t[p += n] = v; p > 1; p >>= 1)
		{
			t[p>>1] = max(t[p], t[p^1]);
		}
	}

	int query(int l, int r)
	{
		int res = 0;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1)
		{
			if(l & 1) res = max(res, t[l++]);
			if(r & 1) res = max(res, t[--r]);
		}
		return res;
	}
};

struct HLD
{
	int n, timer = 0;
	vector<int> siz, depth, head, pos, par;
	vector<vector<int>> adj;
	Segment seg = Segment();

	HLD(vector<int> v, vector<vector<int>> adj) : n(adj.size()), adj(adj)
	{
		siz.resize(n, 1);
		depth.resize(n, 0);
		head.resize(n, 0);
		pos.resize(n, -1);
		par.resize(n, -1);

		dfs(0, -1);
		decompose(0, -1);

		vector<int> tmp(n, 0);
		seg = Segment(n, tmp);
		for(int i = 0; i < n; ++i)
		{
			seg.update(pos[i], v[i]);
		}
	}

	void dfs(int node, int p)
	{
		for(int u: adj[node])
		{
			if(u == p) continue;
			par[u] = node;
			depth[u] = depth[node]+1;
			dfs(u, node);
			siz[node] += siz[u];
		}
		sort(begin(adj[node]), end(adj[node]), [&] (int x, int y)
		{
			return siz[x] > siz[y];
		});
	}

	void decompose(int node, int p)
	{
		bool found_heavy = false;
		pos[node] = timer++;

		for(int u: adj[node])
		{
			if(u == p) continue;
			if(!found_heavy)
			{
				found_heavy = true;
				head[u] = head[node];
			} else
			{
				head[u] = u;
			}
			decompose(u, node);
		}
	}

	void update(int p, int v)
	{
		seg.update(pos[p], v);
	}

	int query(int a, int b)
	{
		int ans = 0;
		while(head[a] != head[b])
		{
			if(depth[head[a]] > depth[head[b]]) swap(a, b);
			ans = max(ans, seg.query(pos[head[b]], pos[b]+1));
			b = par[head[b]];
		}
		
		if(depth[a] > depth[b]) swap(a, b);
		ans = max(ans, seg.query(pos[a], pos[b]+1));

		return ans;
	}
};

void solve(int n, int q, int *briganti, int *a, int *b, int *start, int *end, int *sol)
{
	vector<int> v(n);
	for(int i = 0; i < n; ++i) v[i] = briganti[i];

	vector<vector<int>> adj(n);
	for(int i = 0; i < n-1; ++i)
	{
		adj[a[i]].push_back(b[i]);
		adj[b[i]].push_back(a[i]);
	}

	HLD hld = HLD(v, adj);
	
	for(int i = 0; i < q; ++i)
	{
		sol[i] = hld.query(start[i], end[i]);
	}
}
