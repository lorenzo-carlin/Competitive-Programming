#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;

constexpr ll INF = 1e18;

vector<vector<int>> adj;
vector<ll> v, prendo, nonprendo;

void dfs(int node, int p)
{
	ll pr = 0, nonpr = 0;

	for(int u: adj[node])
	{
		if(u == p) continue;
		dfs(u, node);
		nonpr += prendo[u];
		pr += min(prendo[u], nonprendo[u]);
	}

	pr += v[node];

	prendo[node] = pr;
	nonprendo[node] = nonpr;
}

// STATE:
// True = prendo
// False = non prendo

set<int> sol;
void reconstruct(int node, int p, bool state)
{
	if(state == true)
	{
		sol.insert(node);
		for(int u: adj[node])
		{
			if(u == p) continue;
			if(prendo[u] < nonprendo[u])
			{
				reconstruct(u, node, true);
			} else
			{
				reconstruct(u, node, false);
			}
		}
	} else
	{
		for(int u: adj[node])
		{
			if(u == p) continue;
			reconstruct(u, node, true);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; cin >> n;

	v.resize(n);
	for(auto &i: v) cin >> i;

	adj.resize(n);
	for(int i = 0, a, b; i < n-1; ++i)
	{
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	prendo.resize(n, INF);
	nonprendo.resize(n, INF);

	dfs(0, -1);

	if(prendo[0] < nonprendo[0])
	{
		reconstruct(0, -1, true);
	} else
	{
		reconstruct(0, -1, false);
	}

	cout << sol.size() << "\n";
	for(int el: sol) cout << el+1 << " ";
	cout << "\n";
}
