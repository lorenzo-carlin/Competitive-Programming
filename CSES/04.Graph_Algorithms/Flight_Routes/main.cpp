#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1e18;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k; cin >> n >> m >> k;

	vector<vector<pair<int,int>>> adj(n);
	for(int i = 0, a, b, c; i < m; ++i)
	{
		cin >> a >> b >> c;
		a--; b--;
		adj[a].push_back({b, c});
	}

	vector<vector<ll>> dist(n, vector<ll> (k, INF));
	priority_queue<pair<ll,int>> q;
	q.push({0, 0});
	dist[0][0] = 0;

	while(!q.empty())
	{
		int v =  q.top().second;
		ll d = -q.top().first;
		q.pop();

		if(dist[v][k-1] < d) continue;
		vector<pair<int,int>> tmp = adj[v];

		for(int i = 0; i < tmp.size(); ++i)
		{
			int u = tmp[i].first;
			ll c =  tmp[i].second;

			if(d+c < dist[u][k-1])
			{
				dist[u][k-1] = d+c;
				sort(begin(dist[u]), end(dist[u]));
				q.push({-(d+c), u});
			}
		}
	}

	for(int i = 0; i < k; ++i)
	{
		cout << dist[n-1][i] << " ";
	}
	cout << "\n";
}
