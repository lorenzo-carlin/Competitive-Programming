#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> adj;
vector<pair<int,int>> archi;
vector<bool> vis;
set<int> sol;
bool cond = false;

bool controlla(set<int> s)
{
	for(int i = 0; i < m; ++i)
	{
		if(!s.count(archi[i].first) && !s.count(archi[i].second))
		{
			return false;
		}
	}
	return true;
}

void esplora(int arco, set<int> s)
{
	if(vis[arco])
	{
		esplora(arco+1, s);
	} else
	{
		if(!cond)
		{
			if(s.size() == 10 || arco == m)
			{
				if(controlla(s))
				{
					cond = true;
					sol = s;
				}
			} else
			{
				bool A = s.count(archi[arco].first);
				bool B = s.count(archi[arco].second);
				if(A || B)
				{
					esplora(arco+1, s);
				} else
				{
					set<int> nuovoA = s;
					nuovoA.insert(archi[arco].first);
					esplora(arco+1, nuovoA);

					set<int> nuovoB = s;
					nuovoB.insert(archi[arco].second);
					esplora(arco+1, nuovoB);
				}
			}
		}
	}
}

int riassumi(int n, int m, int a[], int b[], int S[])
{
	::n = n, ::m = m;
	adj.resize(n);
	archi.resize(m);
	vis.resize(m, false);

	for(int i = 0; i < m; ++i)
	{
		archi[i].first = a[i]-1;
		archi[i].second = b[i]-1;
		adj[a[i]-1].push_back(b[i]-1);
		adj[b[i]-1].push_back(a[i]-1);
	}

	set<int> s;
	for(int i = 0; i < n; ++i)
	{
		if(adj[i].size() > 10)
		{
			s.insert(i);
		}
	}

	for(int i = 0; i < m; ++i)
	{
		if(s.count(archi[i].first) || s.count(archi[i].second))
		{
			vis[i] = true;
		}
	}

	esplora(0, s);

	int ind = 0;
	for(int el: sol)
	{
		S[ind++] = el+1;
	}
	return sol.size();
}
