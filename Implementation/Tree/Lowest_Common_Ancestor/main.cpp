/*
 * Lowest Common Ancestor (LCA)
 * Finds the lowest node that is an ancestor of two given nodes in a rooted tree.
 */


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int LOG = 20;

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	// input tree
	int n; cin >> n;
	vector<vector<int>> adj(n);
	for(int i = 0, a, b; i < n-1; ++i)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> euler, depth, first_app(n);
	int tmr = 0;
	auto dfs = [&] (auto dfs, int v, int p, int d) -> void
	{
		euler.push_back(v);
		depth.push_back(d);
		first_app[v] = tmr;
		tmr++;

		for(int u: adj[v])
		{
			if(u == p) continue;
			dfs(dfs, u, v, d+1);
			euler.push_back(v);
			depth.push_back(d);
			tmr++;
		}

		euler.push_back(v);
		depth.push_back(d);
		tmr++;
	};

	dfs(dfs, 0, -1, 0);
	int sz = euler.size();

	vector<vector<pair<int,int>>> sparse_table(LOG, vector<pair<int,int>> (sz));
	for(int i = 0; i < sz; ++i)
	{
		sparse_table[0][i] = {depth[i], euler[i]};
	}

	for(int j = 1; j < LOG; ++j)
	{
		for(int i = 0; i + (1 << j)  < sz; ++i)
		{
			sparse_table[j][i] = min(sparse_table[j-1][i], sparse_table[j-1][i+(1<<(j-1))]);
		}
	}

	int q; cin >> q;
	while(q--)
	{
		int a, b; cin >> a >> b;
		int l = first_app[a], r = first_app[b];
		int k = log2(r-l+1);
		auto ans = min(sparse_table[k][l], sparse_table[k][r-(1 << k)+1]);
		cout << ans.second << "\n";
	}
}
