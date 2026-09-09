#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;

constexpr int LOG = 20;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q; cin >> n >> q;
	vector<int> v(n);
	for(auto &i: v) cin >> i;

	// [0, ..., n-1] -> valori dati
	// [n, ..., n+20] -> potenze di due
	
	vector<vector<pair<int,int>>> adj(n+LOG);
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < LOG; ++j)
		{
			if(v[i] & (1 << j))
			{
				adj[i].push_back({n+j, 0});
				adj[n+j].push_back({i, 1});
			}
		}
	}

	vector<vector<int>> dist(LOG, vector<int> (n+LOG, 1e9));
	for(int j = 0; j < LOG; ++j)
	{
		queue<int> pq; // nodo
		pq.push(n+j);
		dist[j][n+j] = 0;
		while(!pq.empty())
		{
			int v = pq.front();
			pq.pop();

			for(auto [u, q]: adj[v])
			{
				if(dist[j][u] > dist[j][v]+q)
				{
					dist[j][u] = dist[j][v]+q;
					pq.push(u);
				}
			}
		}
	}

	for(int i = 0, a, b; i < q; ++i)
	{
		cin >> a >> b;
		a--; b--;
		int ans = 1e8;
		for(int j = 0; j < LOG; ++j)
		{
			ans = min(ans, dist[j][a]+dist[j][b]-1);
		}
		cout << (ans == 1e8 ? -1 : ans) << "\n";
	}
}
