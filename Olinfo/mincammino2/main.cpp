#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
using namespace std;
using ll = long long;

void mincammino(int n, int m, vector<int> x, vector<int> y, vector<int> p, vector<ll> &d)
{
	vector<vector<pair<int,ll>>> adj(n);
	for(int i = 0; i < m; ++i)
	{
		adj[x[i]].push_back({y[i], p[i]});
	}

	vector<ll> dist(n, 1e18);
	priority_queue<pair<ll,int>> pq;
	pq.push({0, 0});
	while(!pq.empty())
	{
		ll d = -pq.top().first;
		int v = pq.top().second;
		pq.pop();

		if(dist[v] <= d) continue;
		dist[v] = d;

		for(auto [u, q]: adj[v])
		{
			if(d+q < dist[u])
			{
				pq.push({-(d+q), u});
			}
		}
	}

	for(int i = 0; i < n; ++i) d[i] = (dist[i] == 1e18 ? -1 : dist[i]);
}
