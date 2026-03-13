#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr K = 450;

int main()
{
	int n; cin >> n;
	vector<vector<int>> adj(n);
	for(int i = 0, a, b; i < m; ++i)
	{
		cin >> a >> b;
		a--; b--;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> a(n), occ(n, 0);
	vector<vector<int>> comp(n);
	for(int i = 0, b; i < n; ++i)
	{
		cin >> b; b--;
		a[i] = b;
		occ[b]++;
		comp[b].push_back(i);
	}

	ll ans = 0;
	for(int i = 0; i < n; ++i)
	{
		if(occ[i] == 0) continue;
		if(occ[i] <= K)
		{
			// Brute Force O(n^2*logn), da trasformare in O(n^2)
			// controllo ogni coppia di nodi e LCA
		} else
		{
			// Calcolo attraverso il conteggio degli archi
		}
	}
