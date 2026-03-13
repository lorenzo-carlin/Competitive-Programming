#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int INF = 1e9;

vector<int> raccogli(int n, int q, vector<int> &a, vector<int> &b, vector<int> &c, vector<int> &l, vector<int> &t)
{
	vector<vector<int>> adj(n);
	for(int i = 0; i < n-1; ++i)
	{
		adj[a[i]].push_back(b[i]);
		adj[b[i]].push_back(a[i]);
	}

	vector<int> linear(2*n), val(2*n), first_app(n);
	int tmr = 0;
	auto dfs = [&] (auto dfs, int v, int p) -> void
	{
		linear[tmr] = v;
		val[tmr] = c[v];
		first_app[v] = tmr;
		tmr++;

		for(int u: adj[v])
		{
			if(u == p) continue;
			dfs(dfs, u, v);
		}

		linear[tmr] = v;
		val[tmr] = -INF;
		tmr++;
	};
	dfs(dfs, 0, -1);
/*
	cerr << "linear:\n";
	for(int el: linear) cerr << el << " ";
	cerr << "\n";
	cerr << "val:\n";
	for(int el: val) cerr << el << " ";
	cerr << "\n";
	cerr << "first_app:\n";
	for(int el: first_app) cerr << el << " ";
	cerr << "\n";
*/
	vector<int> occ(n, 0);
	vector<int> max1(2*n, -INF);	// max tra i nodi che appaiono 2 volte nel prefix
	vector<int> max2(2*n, -INF); 	// max tra le first_app del suffic
	for(int i = 0; i < 2*n; ++i)
	{
		if(i) max1[i] = max1[i-1];
		occ[linear[i]]++;
		if(occ[linear[i]] == 2) max1[i] = max(max1[i], c[linear[i]]);
	}
	for(int i = 2*n-1; i >= 0; i--)
	{
		if(i<(2*n-1)) max2[i] = max2[i+1];
		max2[i] = max(max2[i], val[i]);
	}
/*
	for(int el: max1) cerr << el << " ";
	cerr << "\n";
	for(int el: max2) cerr << el << " ";
	cerr << "\n";
*/
	vector<int> ans(q);
	for(int i = 0; i < q; ++i)
	{
		int a = l[i], b = t[i];
		if(b == 0) swap(a, b);
		ans[i] = max(max1[first_app[b]], max2[first_app[b]+1]);
	}

	return ans;
}
