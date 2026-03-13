#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void print(int a, int b)
{
	cout << "? " << a << " " << b << "\n";
	cout.flush();
}

void solve()
{
	int n; cin >> n;
	vector<bool> vis(n, false);
	vector<vector<int>> adj(n+1);

	auto explore = [&] (auto explore, int a, int b) -> void
	{
		if(vis[a] && vis[b]) return;

		print(a, b);
		int p; cin >> p;
		if(p == a)
		{
			vis[b] = true;
			adj[a].push_back(b);
			adj[b].push_back(a);
		} else
		{
			explore(explore, a, p);
			explore(explore, p, b);
		}
	};

	int st = 1;
	vis[st] = true;
	for(int i = 2; i <= n; ++i)
	{
		explore(explore, st, i);
	}

	cout << "! ";
	for(int i = 0; i <= n; ++i)
	{
		for(int j: adj[i])
		{
			if(j > i)
			{
				cout << i << " " << j << " ";
			}
		}
	}
	cout << "\n";
	cout.flush();
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
