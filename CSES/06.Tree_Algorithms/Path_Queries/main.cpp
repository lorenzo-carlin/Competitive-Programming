#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Segment
{
	vector<ll> t;
	int n;

	Segment() {}
	Segment(int _n, vector<int> a)
	{
		for(n = 1; n <= _n; n <<= 1);
		t.resize(2*n, 0);
		for(int i = 0; i < _n; ++i) t[i+n] = a[i];
		for(int i = n-1; i >= 0; i--) t[i] = t[i<<1] + t[i<<1|1];
	}

	void update(int p, int v)
	{
		for(t[p += n] = v; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
	}

	ll query(int l, int r)
	{
		ll ans = 0;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1)
		{
			if(l & 1) ans += t[l++];
			if(r & 1) ans += t[--r];
		}
		return ans;
	}
};

struct HLD
{
	int n, timer = 0;
	vector<int> size;
	vector<int> head;
	vector<int> par;
	vector<int> depth;
	vector<int> pos;
	vector<vector<int>> adj;
	Segment seg;


	HLD(vector<int> v, vector<vector<int>> adj) : n(adj.size()), adj(adj)
	{
		size.assign(n, 1);
		head.assign(n, 0);
		par.assign(n, -1);
		depth.assign(n, 0);
		pos.assign(n, -1);

		dfs(0, -1);
		decompose(0, -1);

		vector<int> tmp(n, 0);
		seg = Segment(n, tmp);
		for(int i = 0; i < n; ++i) seg.update(pos[i], v[i]);
	}

	void dfs(int node, int p)
	{
		for(int child: adj[node])
		{
			if(child == p) continue;

			par[child] = node;
			depth[child] = depth[node]+1;
			dfs(child, node);
			size[node] += size[child];
		}
		sort(begin(adj[node]), end(adj[node]), [&] (int x, int y)
		{
			return size[x] > size[y];
		});
	}

	void decompose(int node, int p)
	{
		bool found_heavy = false;
		pos[node] = timer++;

		for(int child: adj[node])
		{
			if(child == p) continue;
			if(!found_heavy)
			{
				found_heavy = true;
				head[child] = head[node];
			} else
			{
				head[child] = child;
			}
			decompose(child, node);
		}
	}

	void update(int p, int v)
	{
		seg.update(pos[p], v);
	}

	ll query(int a, int b)
	{
		ll ans = 0;

		while(head[a] != head[b])
		{
			if(depth[head[a]] > depth[head[b]]) swap(a, b);
			ans += seg.query(pos[head[b]], pos[b]+1);
			b = par[head[b]];
		}

		if(depth[a] > depth[b]) swap(a, b);
		ans += seg.query(pos[a], pos[b]+1);

		return ans;
	}
};

int main()
{
	int n, q; cin >> n >> q;
	vector<int> v(n);
	for(int &i: v) cin >> i;
	vector<vector<int>> adj(n);
	for(int i = 0; i < n-1; ++i)
	{
		int a, b; cin >> a >> b;
		--a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	HLD h = HLD(v, adj);

	for(int i = 0; i < q; ++i)
	{
		int type; cin >> type;
		if(type == 1)
		{
			int a, b; cin >> a >> b; --a;
			h.update(a, b);
		} else
		{
			int a; cin >> a; --a;
			cout << h.query(0, a) << "\n";
		}
	}
}
