#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int sol = 0;
vector<vector<int>> adj;
vector<int> sz;

void dfs(int v)
{
	sz[v] = 0;
	for(int u: adj[v])
	{
		dfs(u);
		sz[v] += sz[u];
	}
	sol += sz[v];
	sz[v]++;
}

int coppie(int n, int c[])
{
	adj.resize(n);
	sz.resize(n, 0);

	int root = -1;
	for(int i = 0; i < n; ++i)
	{
		if(c[i] != -1)
		{
			adj[c[i]].push_back(i);
		} else
		{
			root = i;
		}
	}

	dfs(root);

	return sol;
}
