#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m; cin >> n >> m;
	vector<set<int>> adj(n);
	for(int i = 0, a, b; i < m; ++i)
	{
		cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}

	queue<int> q;
	for(int i = 0; i < n; ++i)
	{
		if(adj[i].size() < 2)
		{
			q.push(i);
		}
	}

	vector<bool> rem(n, false);
	while(!q.empty())
	{
		int n = q.front();
		q.pop();

		if(adj[n].size() < 2)
		{
			for(int el: adj[n])
			{
				adj[el].erase(n);
				q.push(el);
			}
			rem[n] = true;
		}
	}

	int sol = 0;
	for(int i = 0; i < n; ++i)
	{
		if(rem[i] == false)
		{
			sol++;
		}
	}

	cout << sol << "\n";
}
