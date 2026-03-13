#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	double dist[n][n];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			dist[i][j] = 0.0;
	for(int i = 0; i < n; ++i)
		dist[i][i] = 1.0;
	for(int i = 0, a, b, c; i < m; ++i)
	{
		cin >> a >> b >> c;
		dist[a][b] = 1.0-c/1000.0;
	}

	for(int x = 0; x < n; ++x)
	{
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if(dist[i][j] < dist[i][x]*dist[x][j])
				{
					dist[i][j] = dist[i][x]*dist[x][j];
				}
			}
		}
	}

	double mn = 1000.0;
	pair<int,int> ans;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(i == j) continue;
			if(dist[i][j] < mn)
			{
				mn = dist[i][j];
				ans = {i, j};
			}
		}
	}

	cout << ans.first << " " << ans.second << "\n";
}
