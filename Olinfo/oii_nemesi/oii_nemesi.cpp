#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
 * Cerco (se c'è) il ciclo del grafo
 * Calcolo il numero di nodi nel ciclo
 * Se è dispari: metto un nodo in un set da solo, poi il restante ciclo lo bipartiziono
 * Se è pari: bipartiziono il ciclo
 * Faccio partire una visita da ogni nodo del ciclo e bipartiziono ciò che resta (si può sempre fare con alpiù due colori)
*/

enum
{
	one,
	two,
	three,
	null
};

void nuovo_gruppo();

void aggiungi(int bambino);

void smista(int n, int nemico[])
{
	vector<int> colore(n, null);
	vector<vector<int>> adj(n);
	for(int i = 0; i < n; ++i)
	{
		adj[i].push_back(nemico[i]);
		adj[nemico[i]].push_back(i);
	}
	
	stack<int> s;
	vector<int> stato(n, 0);
	bool trovato;
	auto dfs = [&](auto dfs, int v, int p) -> void
	{
		if(trovato) return;

		stato[v] = 1;
		s.push(v);
		for(int u: adj[v])
		{
			if(u == p) continue;
			if(trovato) return;

			if(stato[u] == 0) dfs(dfs, u, v);
			else if(stato[u] == 1) trovato = true;
		}
		
		if(trovato) return;

		s.pop();
		stato[v] = 2;
	};

	auto bipartizione = [&] (auto bipartizione, int v, bool cond) -> void
	{
		if(cond) colore[v] = one;
		else colore[v] = two;

		for(int u: adj[v])
		{
			if(colore[u] != null) continue;
			bipartizione(bipartizione, u, !cond);
		}
	};

	for(int i = 0; i < n; ++i)
	{
		if(colore[i] != null) continue;

		trovato = false;
		dfs(dfs, i, -1);

		set<int> ciclo;
		int sz = s.size();

		if(sz & 1)
		{
			colore[s.top()] = three;
			ciclo.insert(s.top());
			s.pop();
		}

		bool cond = true;
		while(!s.empty())
		{
			if(cond) colore[s.top()] = one;
			else colore[s.top()] = two;
			cond = !cond;

			ciclo.insert(s.top());
			s.pop();
		}

		if(!trovato)
		{
			bipartizione(bipartizione, 0, true);
		} else
		{
			for(int el: ciclo)
			{
				if(colore[el] == one) bipartizione(bipartizione, el, true);
				else if(colore[el] == two) bipartizione(bipartizione, el, false);
				else
				{
					for(int u: adj[el])
					{
						if(colore[u] == null) bipartizione(bipartizione, u, true);
					}
				}
			}
		}

	}

	nuovo_gruppo();
	for(int i = 0; i < n; ++i) if(colore[i] == one) aggiungi(i);

	nuovo_gruppo();
	for(int i = 0; i < n; ++i) if(colore[i] == two) aggiungi(i);

	nuovo_gruppo();
	for(int i = 0; i < n; ++i) if(colore[i] == three) aggiungi(i);
}

