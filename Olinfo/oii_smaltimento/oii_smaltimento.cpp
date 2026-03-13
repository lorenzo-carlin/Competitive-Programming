#include  <bits/stdc++.h>
using namespace std;
using ll = long long;

ll smaltisci(int n, int m, vector<int> a, vector<vector<int>> b)
{
	vector<vector<pair<int,int>>> adj(n), adj_inv(n);
	vector<int> stops, processi0;
	for(int i = 0; i < m; ++i)
	{
		for(int el: b[i])
		{
			adj[a[i]].push_back({el,i});
			adj_inv[el].push_back({a[i],i});
		}
		if(b[i].empty())
		{
			stops.push_back(a[i]);
		}
		if(a[i] == 0)
		{
			processi0.push_back(i);
		}
	}

	priority_queue<pair<ll,int>> q;
	vector<ll> dist(n, 1e18);
	for(int el: stops)
	{
		q.push({-1,el});
	}

	auto calcolaprocesso = [&] (int processo) -> ll
	{
		ll ans = 1;
		for(int el: b[processo])
		{
			if(dist[el] == 1e18)
			{
				return -1;
			} else
			{
				ans += dist[el];
			}
		}
		return ans;
	};

	while(!q.empty())
	{
		ll  d = -q.top().first;
		int n =  q.top().second;
		q.pop();

		if(dist[n] <= d || n == 0) continue;
		dist[n] = d;

		for(auto v: adj_inv[n])
		{
			// cout << "v: " << v.first << "\n";
			ll newd = calcolaprocesso(v.second);
			if(newd == -1) continue;
			q.push({-newd,v.first});
		}
	}

	ll sol = 1e18;
	for(int el: processi0)
	{
		ll tmp = calcolaprocesso(el);
		if(tmp == -1) continue;
		sol = min(sol, tmp);
	}

	/*
	for(int i = 0; i < n; ++i)
	{
		cout << i << ": " << dist[i] << "\n";
	}
	*/

	return sol;
}
