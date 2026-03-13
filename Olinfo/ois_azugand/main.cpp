#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int LOG = 20;
constexpr int INF = 1e9;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q; cin >> n >> q;
	vector<int> v(n);
	for(int &i: v) cin >> i;

	// adji[i] = j, v[i] è connesso a (1 << j)
	// adjj[j] = i, (1 << j) è connesso a v[i]
	vector<vector<int>> adji(n);
	vector<vector<int>> adjj(LOG);
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < LOG; ++j)
		{
			if(v[i] & (1 << j))
			{
				adji[i].push_back(j);
				adjj[j].push_back(i);
			}
		}
	}

	vector<vector<int>> dist(LOG, vector<int> (n, INF));
	for(int j = 0; j < LOG; ++j)
	{
		// {nodo, distanza, cond}
		// cond = true, se analizziamo un nodo inesistente (potenza di due)
		// cond = false, se analizziamo un nodo esistente (un nodo di v)
		queue<array<int,3>> q;
		q.push({j, 0, true});

		while(!q.empty())
		{
			int node  = q.front()[0];
			int dis   = q.front()[1];
			bool cond = q.front()[2];
			q.pop();

			if(cond) // siamo in un nodo inesistente
			{
				for(int v: adjj[node])
				{
					if(dist[j][v] != INF) continue;
					q.push({v, dis+1, false});
				}
			} else // siamo in un nodo esistente
			{
				if(dis >= dist[j][node]) continue;
				dist[j][node] = dis;

				for(int v: adji[node])
				{
					q.push({v, dis, true});
				}
			}
		}
	}

	for(int i = 0, a, b; i < q; ++i)
	{
		cin >> a >> b;
		a--; b--;
		int mn = INF;
		for(int j = 0; j < LOG; ++j)
		{
			mn = min(mn, dist[j][a]+dist[j][b]-1);
		}

		int ans = (mn >= 1e9) ? (-1) : (mn);
		cout << ans << "\n";
	}

}	
