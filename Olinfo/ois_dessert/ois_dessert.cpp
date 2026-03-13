#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<vector<int>> adj(n);
	vector<vector<int>> par(n);
	vector<int> lim(n), cnt(n, 0);
	vector<bool> vis(n, false);
	for(int i = 0; i < n; ++i)
	{
		int m, l; cin >> m >> l;
		lim[i] = l;
		for(int j = 0; j < m; ++j)
		{
			int a; cin >> a;
			adj[i].push_back(a);
			par[a].push_back(i);
		}
	}

	queue<int> q;
	for(int i = 0; i < n; ++i)
	{
		if(lim[i] == 0) q.push(i);
	}
	while(!q.empty())
	{
		int n = q.front();
		q.pop();
		
		if(vis[n]) continue;
		vis[n] = true;

		for(int el: par[n])
		{
			cnt[el]++;
			if(cnt[el] >= lim[el])
			{
				q.push(el);
			}
		}
	}

	int sol = 0;
	for(int i = 0; i < n; ++i)
	{
		if(vis[i]) sol++;
	}

	cout << sol << "\n";
}	
