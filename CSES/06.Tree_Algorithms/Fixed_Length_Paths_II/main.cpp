#include <iostream>
#include <vector>
#include <bitset>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
using namespace std;
using ll = long long;

constexpr int MAXN = 2e5+5;

struct Centroid
{
	vector<vector<int>> adj;
	vector<int> size, freq, ps;
	bitset<MAXN> rem;
	int k1, k2, mx_depth = 0, new_mx_depth = 0;
	ll ans = 0;

	Centroid(vector<vector<int>> &adj, int k1, int k2) : adj(adj), k1(k1), k2(k2)
	{
		int n = adj.size();
		size.resize(n, 0);
		freq.resize(n, 0);
		ps.resize(n, 0);
		build(0, -1);
	}

	int dfs(int v, int p)
	{
		if(rem[v]) return 0;
		size[v] = 1;
		for(int u: adj[v])
		{
			if(u == p || rem[u]) continue;
			size[v] += dfs(u, v);
		}
		return size[v];
	}

	int find_centroid(int v, int p, int dim)
	{
		for(int u: adj[v])
		{
			if(u != p && !rem[u] && size[u] > dim/2)
			{
				return find_centroid(u, v, dim);
			}
		}
		return v;
	}

	void count(int v, int p, int d, bool cond)
	{
		if(d > k2) return;
		new_mx_depth = (new_mx_depth < d) ? d : new_mx_depth;
		int tmp_l = (k2-d+1 > 0) ? (k2-d+1) : 0;
		int l = (mx_depth+1 < tmp_l) ? (mx_depth+1) : tmp_l;
		int tmp_r = (k1-d > 0) ? (k1-d) : 0;
		int r = (mx_depth+1 < tmp_r) ? (mx_depth+1) : tmp_r;

		if(cond)
		{
			ans += (ps[l]-ps[r]);
		} else
		{
			freq[d]++;
		}

		for(int u: adj[v])
		{
			if(u == p || rem[u]) continue;
			count(u, v, d+1, cond);
		}
	}

	void build(int v, int p)
	{
		int dim = dfs(v, p);
		int cen = find_centroid(v, p, dim);

		freq[0] = 1; ps[1] = 1;
		mx_depth = 0, new_mx_depth = 0;
		for(int u: adj[cen])
		{
			if(u == p || rem[u]) continue;
			count(u, cen, 1, true);
			count(u, cen, 1, false);
			mx_depth = (mx_depth > new_mx_depth) ? mx_depth : new_mx_depth;
			for(int i = 1; i <= mx_depth+1; i++)
			{
				ps[i] = ps[i-1] + freq[i-1];
			}
		}

		for(int i = 0; i <= mx_depth+1; ++i)
		{
			freq[i] = 0;
			ps[i] = 0;
		}
		rem[cen] = true;

		// cout << ans << "\n";

		for(int u: adj[cen])
		{
			if(u == p || rem[u]) continue;
			build(u, cen);
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k1, k2; cin >> n >> k1 >> k2;
	vector<vector<int>> adj(n);
	for(int i = 0; i < n-1; ++i)
	{
		int a, b; cin >> a >> b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	if(k1 == k2 && k1 == n)
	{
		cout << 0 << "\n";
	} else if(k1 == 1 && k2 == n)
	{
		cout << (ll) n*(n-1)/2 << "\n";
	} else
	{
		Centroid centroid = Centroid(adj, k1, k2);
		cout << centroid.ans << "\n";
	}
}
