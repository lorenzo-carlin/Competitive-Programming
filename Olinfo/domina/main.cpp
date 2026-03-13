#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> adj, adjR;
vector<bool> occ, qk;

void solve()
{
	// Scelgo un nodo a caso (il primo della lista).
	int nodo = -1;
	vector<int> vicini;
	for(int i = 0; i < n; ++i)
	{
		if(!occ[i])
		{
			nodo = i;
			break;
		}
	}

	// caso base: il grafo è vuoto e quindi anche il quasi-kernel
	if(nodo == -1) return;

	// se il grafo non è vuoto, escludo il nodo scelto e i suoi vicini uscenti
	occ[nodo] = true;
	for(int vicino: adj[nodo])
	{
		if(occ[vicino]) continue;
		vicini.push_back(vicino);
		occ[vicino] = true;
	}

	// trovo il quasi-kernel del sottografo
	solve();

	occ[nodo] = false;
	for(int vicino: vicini)
	{
		occ[vicino] = false;
	}

	// controllo se il quasi-kernel del sottografo rimane valido
	// controllo della proprietà 2:
	vicini.push_back(nodo);
	bool valida = true;
	for(int u: vicini)
	{
		bool trovato = false;
		for(int v1: adjR[u])
		{
			if(occ[v1]) continue;
			if(qk[v1])
			{
				trovato = true;
				break;
			}
			for(int v2: adjR[v1])
			{
				if(occ[v2]) continue;
				if(qk[v2])
				{
					trovato = true;
					break;
				}
			}
		}
		if(!trovato) valida = false;
	}

	if(valida)
	{
		return;
	} else
	{
		// devo aggiungere nodo
		qk[nodo] = true;
	}
}	

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> m;
	adj.resize(n);
	adjR.resize(n);
	occ.resize(n);
	qk.resize(n);

	for(int i = 0, a, b; i < m; ++i)
	{
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adjR[b].push_back(a);
	}

	solve();

	for(int i = 0; i < n; ++i)
	{
		if(qk[i])
		{
			cout << i+1 << " ";
		}
	}
	cout << "\n";
}
