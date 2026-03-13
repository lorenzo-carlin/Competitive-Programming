#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> G, Gt;
vector<int> order, component;
vector<bool> vis;

void dfs1(int n)
{
	vis[n] = true;

	for(int v: G[n])
	{
		if(!vis[v])
		{
			dfs1(v);
		}
	}

	order.push_back(n);
}

void dfs2(int n)
{
	vis[n] = true;
	component.push_back(n);
	
	for(int v: Gt[n])
	{
		if(!vis[v])
		{
			dfs2(v);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	G.resize(n);
	Gt.resize(n);
	vis.resize(n, false);

	for(int i = 0, a, b; i < m; ++i)
	{
		cin >> a >> b;
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

	// for(auto el: order) cout << el+1 << " ";
	// cout << "\n";

	vis.assign(n, false);
	vector<int> sol(n);

	int ind = 1;
	for(int i = 0; i < n; ++i)
	{
		if(!vis[order[i]])
		{
			dfs2(order[i]);
			for(auto el: component)
			{
				sol[el] = ind;
			}
			component.clear();
			ind++;
		}
	}

	cout << ind-1 << "\n";
	for(auto el: sol)
	{
		cout << el << " ";
	}
	cout << "\n";
}
