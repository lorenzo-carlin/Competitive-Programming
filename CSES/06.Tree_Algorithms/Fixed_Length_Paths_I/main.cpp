#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct centroid
{
	vector<vector<int>> adj;
	vector<int> size;
	vector<int> freq;
	vector<bool> rem;
	int mx_depth = 0;
	ll ans = 0;
	int k;

	centroid(vector<vector<int>> &adj, int k) : adj(adj), k(k)
	{
		int n = adj.size();
		size.resize(n, 0);
		freq.resize(n, 0);
		rem.resize(n, false);
		build(0, -1);
	}

	int dfs(int u, int p)
	{
		if(rem[u]) return 0;

		size[u] = 1;
		for(int v: adj[u])
		{
			if(v == p) continue;
			size[u] += dfs(v, u);
		}
		return size[u];
	}

	int findCentroid(int u, int p, int dim)
	{
		for(int v: adj[u])
		{
			if(v != p && size[v] > dim/2 && !rem[v])
			{
				return findCentroid(v, u, dim);
			}
		}
		return u;
	}

	void count(int u, int p, int depth, bool cond)
	{
		if(depth > k) return;
		mx_depth = max(mx_depth, depth);

		if(cond)
		{
			ans += freq[k-depth];
		} else
		{
			freq[depth]++;
		}

		for(int v: adj[u])
		{
			if(v == p || rem[v]) continue;
			count(v, u, depth+1, cond);
		}
	}

	void build(int u, int p)
	{
		int dim = dfs(u, p);
		int cen = findCentroid(u, p, dim);

		freq[0] = 1;
		mx_depth = 0;
		for(int v: adj[cen])
		{
			if(v == p || rem[v]) continue;
			count(v, cen, 1, true);
			count(v, cen, 1, false);
		}

		for(int i = 0; i <= mx_depth; ++i)
		{
			freq[i] = 0;
		}
		rem[cen] = true;

		for(int v: adj[cen])
		{
			if(rem[v]) continue;
			build(v, cen);
		}
	}
};	

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k; cin >> n >> k;
	vector<vector<int>> adj(n);
	for(int i = 0; i < n-1; ++i)
	{
		int a, b; cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	centroid C = centroid(adj, k);

	cout << C.ans << "\n";
}
