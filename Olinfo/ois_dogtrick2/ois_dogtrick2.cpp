#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> order, component, toposort, tmp, in;
vector<vector<int>> adj, adj_rev, GSCC;
vector<unordered_set<int>> nextt;
vector<bool> vis;
int tmr = 0;
int n, k, m;

void dfs1(int v)
{
	vis[v] = true;
	for(int u: adj[v])
	{
		if(!vis[u])
		{
			dfs1(u);
		}
	}
	order.push_back(v);
}

void dfs2(int v, int val)
{
	vis[v] = true;
	component[v] = val;
	for(int u: adj_rev[v])
	{
		if(!vis[u])
		{
			dfs2(u, val);
		}
	}
}

void dfs3(int v)
{
	vis[v] = true;
	for(int u: adj[v])
	{
		if(component[v] != component[u])
		{
			GSCC[component[v]].push_back(component[u]);
			in[component[u]]++;
		}
	}
	for(int u: adj[v])
	{
		if(!vis[v] && component[v] == component[u])
		{
			dfs3(u);
		}
	}
}

bool find_path(int a, int b)
{
	if(a == b) return true;
	if(toposort[a] > toposort[b]) return false;

	for(int u: GSCC[a])
	{
		if(toposort[u] > toposort[b]) continue;
		if(find_path(u, b)) return true;
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i];
		v[i]--;
	}

	adj.resize(k); adj_rev.resize(k); nextt.resize(k);
	cin >> m;
	for(int i = 0, a, b; i < m; ++i)
	{
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj_rev[b].push_back(a);
		nextt[a].insert(b);
	}

	vis.assign(k, false);
	for(int i = 0; i < k; ++i)
	{
		if(!vis[i])
		{
			dfs1(i);
		}
	}

	reverse(begin(order), end(order));
	vis.assign(k, false);
	component.resize(k, -1);
	int val = 0;
	for(int i: order)
	{
		if(!vis[i])
		{
			dfs2(i, val++);
		}
	}

	GSCC.resize(val);
	in.resize(val, 0);
	vis.assign(k, false);
	for(int i = 0; i < k; ++i)
	{
		if(!vis[i])
		{
			dfs3(i);
		}
	}

	queue<int> q;
	for(int i = 0; i < val; ++i)
	{
		if(in[i] == 0)
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		tmp.push_back(v);
		for(int u: GSCC[v])
		{
			if(--in[u] == 0) q.push(u);
		}
	}

	toposort.resize(val);
	for(int i = 0; i < val; ++i)
	{
		toposort[tmp[i]] = i;
	}

	int pnt = 2;
	for(int i = 0; i < n-1; i++)
	{
		int x = v[i];
		int y = v[i+1];

		if(nextt[x].count(y))
		{
			pnt += 2;
		} else if(find_path(component[x], component[y]))
		{
			pnt++;
		} else
		{
			break;
		}
	}

	cout << pnt << "\n";
}
