#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int sbugiarda(int n, vector<int> h)
{
	vector<vector<int>> adj(n);
	stack<int> s;
	vector<int> roots;
	for(int i = n-1; i >= 0; i--)
	{
		while(!s.empty() && h[i] >= h[s.top()]) s.pop();
		if(s.empty())
		{
			roots.push_back(i);
		} else
		{
			adj[i].push_back(s.top());
			adj[s.top()].push_back(i);
		}
		s.push(i);
	}

	vector<int> left(n, 0);
	auto dfs1 = [&] (auto self, int v, int p) -> void
	{
		for(int u: adj[v])
		{
			if(u == p) continue;
			self(self, u, v);
			left[v] = max(left[v], left[u]+1);
		}
	};
	for(int el: roots) dfs1(dfs1, el, -1);

	adj.clear();
	adj.resize(n);
	while(!s.empty()) s.pop();
	roots.clear();
	for(int i = 0; i < n; ++i)
	{
		while(!s.empty() && h[i] >= h[s.top()]) s.pop();
		if(s.empty()) roots.push_back(i);
		else
		{
			adj[i].push_back(s.top());
			adj[s.top()].push_back(i);
		}
		s.push(i);
	}

	vector<int> right(n, 0);
	auto dfs2 = [&] (auto self, int v, int p) -> void
	{
		for(int u: adj[v])
		{
			if(u == p) continue;
			self(self, u, v);
			right[v] = max(right[v], right[u]+1);
		}
	};
	for(int el: roots) dfs2(dfs2, el, -1);

	int ans = 0;
	vector<int> cnt(n, 0);
	for(int i = 0; i < n; ++i) cnt[right[i]]++;
	int ind = n-1;
	for(int i = 0; i < n; ++i)
	{
		// caso 1: una torre sola
		ans = max(ans, right[i]+left[i]+1);

		// caso 2: due torri opposte
		cnt[right[i]]--;
		while(!cnt[ind]) ind--;
		ans = max(ans, left[i] + ind + 2);
	}

	return ans;
}
