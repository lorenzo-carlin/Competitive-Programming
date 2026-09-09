#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<vector<int>> nodi_per_altezza;
int hmax = 0;

void assegna_altezze(int v, int p, int h)
{
	// espando nodi_per_altezza se serve
	while(nodi_per_altezza.size() <= (h+1)) nodi_per_altezza.push_back({});
	nodi_per_altezza[h].push_back(v);
	hmax = max(h, hmax);

	for(int u: adj[v])
	{
		if(u == p) continue;
		assegna_altezze(u, v, h+1);
	}
}

int pota(int n, vector<int> p)
{
	adj.resize(n);
	for(int i = 1; i < n; ++i)
	{
		adj[i].push_back(p[i]);
		adj[p[i]].push_back(i);
	}

	assegna_altezze(0, -1, 0);

	vector<bool> vis(n, false);
	int ans = 0, cnt = 0;
	for(int i = hmax; i >= 0; i--)
	{
		if(i < hmax) cnt -= nodi_per_altezza[i+1].size();
		for(int v: nodi_per_altezza[i])
		{
			int cur = v;
			while(cur >= 0 && !vis[cur])
			{
				vis[cur] = true;
				cur = p[cur];
				cnt++;
			}
		}
		ans = max(ans, cnt);
	}

	return n-ans;
}
