#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1e18;
struct nodo
{
	ll sum = 0;
	ll max_prefix = 0;
	ll max_suffix = 0;
	ll max_sub = 0;

	nodo (ll num) : sum(num), max_prefix(num), max_suffix(num), max_sub(num) {}
	nodo () {}
};

void print(nodo a)
{
	cout << "sum: " << a.sum << "\n";
	cout << "max_prefix: " << a.max_prefix << "\n";
	cout << "max_suffix: " << a.max_suffix << "\n";
	cout << "max_sub: " << a.max_sub << "\n";
}

nodo merge(nodo a, nodo b)
{
	nodo sol;
	sol.sum = a.sum+b.sum;
	sol.max_prefix = max(a.max_prefix, a.sum+b.max_prefix);
	sol.max_suffix = max(b.max_suffix, b.sum+a.max_suffix);
	sol.max_sub = max(max(a.max_sub, b.max_sub), a.max_suffix+b.max_prefix);
	return sol;
}

constexpr int LOG = 20;
vector<vector<int>> up, mn;
vector<vector<nodo>> subpath;
vector<vector<pair<int,int>>> adj;
vector<int> depth;
vector<ll> sum;

int N;

void dfs(int n, int p)
{
	for(auto q: adj[n])
	{
		if(q.first == p) continue;
		up[q.first][0] = n;
		depth[q.first] = depth[n]+1;
		mn[q.first][0] = q.second;
		subpath[q.first][0] = nodo(q.second);
		sum[q.first] = sum[n]+((ll)q.second);
		dfs(q.first, n);
	}
}

int lift(int n, int k)
{
	for(int i = 0; i < LOG; i++)
	{
		if(n == -1) break;

		if(k & (1 << i)) n = up[n][i];
	}

	return n;
}

int LCA(int a, int b)
{
	if(depth[a] > depth[b]) swap(a, b);
	b = lift(b, depth[b]-depth[a]);

	if(a == b) return a;

	for(int i = LOG-1; i >= 0; i--)
	{
		if(up[a][i] != up[b][i])
		{
			a = up[a][i];
			b = up[b][i];
		}
	}

	return up[a][0];
}

ll distanza1(int u, int v)
{
	int l = LCA(u, v);
	int ans = depth[u]+depth[v]-2*depth[l];
	return ans;
}

ll distanza2(int u, int v)
{
	int l = LCA(u, v);
	ll ans = sum[u]+sum[v]-2*sum[l];
	return ans;
}

ll minimo(int u, int v)
{
	int l = LCA(u, v);

	int dif_u = depth[u]-depth[l];
	int mn1 = INT_MAX;
	for(int i = 0; i < LOG; ++i)
	{
		if(dif_u & (1 << i))
		{
			mn1 = min(mn1, mn[u][i]);
			u = up[u][i];
		}
	}

	int dif_v = depth[v]-depth[l];
	int mn2 = INT_MAX;
	for(int i = 0; i < LOG; ++i)
	{
		if(dif_v & (1 << i))
		{
			mn2 = min(mn2, mn[v][i]);
			v = up[v][i];
		}
	}

	return min(mn1, mn2);
}

ll massimo(int u, int v)
{
	int l = LCA(u, v);

	int dif_u = depth[u]-depth[l];
	nodo sub_u;
	for(int i = 0; i < LOG; ++i)
	{
		if(dif_u & (1 << i))
		{
			sub_u = merge(sub_u, subpath[u][i]);
			u = up[u][i];
		}
	}

	int dif_v = depth[v]-depth[l];
	nodo sub_v;
	for(int i = 0; i < LOG; ++i)
	{
		if(dif_v & (1 << i))
		{
			sub_v = merge(sub_v, subpath[v][i]);
			v = up[v][i];
		}
	}

	ll ans = max(max(sub_u.max_sub, sub_v.max_sub), sub_u.max_suffix+sub_v.max_suffix);
	return ans;
}

void inizia(int n, int t, int a[], int b[], int c[])
{
	N = n;
	adj.resize(N);
	sum.resize(N, 0);
	depth.resize(N, 0);
	up.resize(N, vector<int> (LOG, -1));
	mn.resize(N, vector<int> (LOG, INT_MAX));
	subpath.resize(N, vector<nodo> (LOG));

	for(int i = 0; i < N-1; ++i)
	{
		adj[a[i]].push_back({b[i], c[i]});
		adj[b[i]].push_back({a[i], c[i]});
	}

	dfs(0, -1);

	for(int j = 1; j < LOG; j++)
	{
		for(int i = 0; i < N; i++)
		{
			if(up[i][j-1] == -1) up[i][j] = -1;
			else up[i][j] = up[up[i][j-1]][j-1];

			int mn1 = mn[i][j-1];
			int mn2 = (up[i][j-1] == -1) ? (INT_MAX) : (mn[up[i][j-1]][j-1]);
			mn[i][j] = min(mn1,mn2);

			if(up[i][j-1] != -1)
			{
				subpath[i][j] = merge(subpath[i][j-1], subpath[up[i][j-1]][j-1]);
			}
		}
	}
}

