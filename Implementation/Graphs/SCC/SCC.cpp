#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// SCC = Strongly Connected Components

vector<vector<int>> G;
vector<vector<int>> Gt;
vector<int> order;
vector<bool> vis;
vector<int> component;

void dfs1(int n)
{
	vis[n] = true;
	for(auto i: G[n])
	{
		if(!vis[i])
		{
			dfs1(i);
		}
	}
	order.push_back(n);
}

void dfs2(int n)
{
	component.push_back(n);
	vis[n] = true;

	for(auto i: Gt[n])
	{
		if(!vis[i])
		{
			dfs2(i);
		}
	}
}


int main()
{
	int n, m; cin >> n >> m;
	G.resize(n);
	Gt.resize(n);
	vis.assign(n, false);
	for(int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		Gt[b].push_back(a);
	}

	for(int i = 0; i < n; ++i)
	{
		if(!vis[i])
		{
			dfs1(i);
		}
	}

	reverse(begin(order), end(order));
	vis.assign(n, false);

	// Condensation graph

	vector<int> root(n, 0), root_nodes;
	vector<set<int>> GSCC(n);

	for(auto v: order)
	{
		if(!vis[v])
		{
			dfs2(v);

			int r = component.front();
			for(auto u: component)
			{
				root[u] = r;
			}
			root_nodes.push_back(r);
			
			component.clear();
		}
	}

	for(int i = 0; i < n; ++i)
	{
		for(auto u: G[i])
		{
			int root_i = root[i];
			int root_u = root[u];

			if(root_i != root_u)
			{
				GSCC[root_i].insert(root_u);
			}
		}
	}

	for(int i = 0; i < n; ++i)
	{
		cout << i << ": ";
		for(auto el: GSCC[i])
		{
			cout << el << " ";
		}
		cout << "\n";
	}
}
