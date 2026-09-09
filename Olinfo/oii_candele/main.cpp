#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;

void brucia(int n, vector<int> &m, vector<int> &b, vector<ll> &t)
{
	vector<array<int,3>> v(n);
	for(int i = 0; i < n; ++i)
	{
		v[i] = {m[i], b[i], i};
	}

	sort(begin(v), end(v));

	vector<vector<pair<int,int>>> adj(n);

	stack<pair<int,int>> s;
	for(int i = 0; i < n; ++i)
	{
		while(!s.empty() && ((v[i][0] >= s.top().first && v[i][1] <= s.top().first) || (v[i][0] <= s.top().first && v[i][1] >= s.top().first)))
		{
			adj[v[i][2]].push_back({s.top().second, v[i][0]-s.top().first});
			s.pop();
		}
		s.push({v[i][0], v[i][2]});
	}

	s = {};
	for(int i = n-1; i >= 0; i--)
	{
		while(!s.empty() && ((v[i][0] <= s.top().first && v[i][1] >= s.top().first) || (v[i][0] >= s.top().first && v[i][1] <= s.top().first)))
		{
			adj[v[i][2]].push_back({s.top().second, s.top().first-v[i][0]});
			s.pop();
		}
		s.push({v[i][0], v[i][2]});
	}

	vector<ll> dist(n, 1e18);
	priority_queue<pair<ll,int>> q;
	q.push({0, 0});
	while(!q.empty())
	{
		ll d = -q.top().first;
		int n = q.top().second;
		q.pop();

		if(dist[n] <= d) continue;
		dist[n] = d;

		for(auto v: adj[n])
		{
			ll newd = d+(ll)v.second;
			q.push({-newd, v.first});
		}
	}

	for(int i = 0; i < n; ++i)
	{
		t[i] = (dist[i] == 1e18) ? (-1) : (dist[i]);
	}
}
