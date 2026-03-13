#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	string s; cin >> s;

	vector<vector<int>> f(n, vector<int> (26, 0));
	vector<vector<int>> adj(n);
	vector<int> deg(n, 0);

	for(int i = 0, a, b; i < m; ++i)
	{
		cin >> a >> b; a--; b--;
		adj[a].push_back(b);
		deg[b]++;
	}

	bool impossible = false;
	vector<int> col(n, 0);

	auto dfs = [&] (auto dfs, int v) -> void
	{
		col[v] = 1;

		for(int u: adj[v])
		{
			if(col[u] == 1) impossible = true;
			if(col[u] == 0) dfs(dfs, u);
		}

		col[v] = 2;
	};

	for(int i = 0; i < n; ++i)
	{
		if(col[i] == 0) dfs(dfs, i);
	}

	if(impossible)
	{
		cout << -1 << "\n";
		return 0;
	}

	queue<int> q;
	
	for(int i = 0; i < n; ++i)
	{
		if(deg[i] == 0)
		{
			q.push(i);
			f[i][s[i]-'a']++;
		}
	}

	while(!q.empty())
	{
		int v = q.front();
		q.pop();

		for(int u: adj[v])
		{
			for(int j = 0; j < 26; ++j)
			{
				f[u][j] = max(f[u][j], f[v][j]);
			}
			deg[u]--;
			if(deg[u] == 0)
			{
				f[u][s[u]-'a']++;
				q.push(u);
			}
		}
	}

	int mx = 0;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < 26; ++j)
		{
			mx = max(mx, f[i][j]);
		}
	}

	cout << mx << "\n";
}
