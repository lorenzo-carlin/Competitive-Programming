#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, p; cin >> n >> p;
	vector<vector<int>> adj(n), adj_rev(n);
	vector<int> v(n);
	for(auto &i: v) cin >> i;
	for(int i = 1; i < n; ++i)
	{
		if(v[i] >= v[i-1])
		{
			adj[i].push_back(i-1);
			adj_rev[i-1].push_back(i);
		}
	}
	for(int i = 0; i < n-1; ++i)
	{
		if(v[i] >= v[i+1])
		{
			adj[i].push_back(i+1);
			adj_rev[i+1].push_back(i);
		}
	}

	vector<int> dist(n, 1e9);
	queue<pair<int,int>> q;
	for(int i = 0; i < n; ++i)
	{
		if(adj_rev[i].empty())
		{
			q.push({1, i});
		}
	}
	while(!q.empty())
	{
		int node = q.front().second;
		int d = q.front().first;
		q.pop();

		bool cond = true;
		for(int u: adj_rev[node])
		{
			if(dist[u] == 1e9)
			{
				cond = false;
			}
		}
		if(cond)
		{
			dist[node] = d;
		} else
		{
			continue;
		}
		
		for(int u: adj[node])
		{
			q.push({d+1, u});
		}
	}

	int ans = 0;
	for(int i = 0; i < n; ++i)
	{
		if(v[i] <= p)
		{
			ans++;
		}
	}

	cout << ans << "\n";
}
