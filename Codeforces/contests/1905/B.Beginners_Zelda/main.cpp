#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<vector<int>> adj(n);
	for(int i = 0, a, b; i < n-1; ++i)
	{
		cin >> a >> b;
		a--; b--;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int leaves = 0;
	for(int i = 0; i < n; ++i)
	{
		if(adj[i].size() == 1)
		{
			leaves++;
		}
	}

	cout << (leaves+1) / 2 << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
