#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	vector<bitset<18>> adj(n);

	for(int i = 0, a, b; i < m; ++i)
	{
		cin >> a >> b; a--; b--;
		adj[a][b] = adj[b][a] = 1;
	}

	vector<int> dp((1 << n), 1e9);
	for(int i = 0; i < (1 << n); i++)
	{
		bool cond = true;
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < j; k++)
			{
				if((i & (1 << j)) && (i & (1 << k)) && !adj[j][k])
				{
					cond = false;
				}
			}
		}
		if(cond) dp[i] = 1;
	}

	for(int i = 0; i < (1 << n); i++)
	{
		for(int j = i; j > 0; j = (j-1) & i)
		{
			if(dp[j] == 1e9 || dp[i^j] == 1e9) continue;
			dp[i] = min(dp[i], dp[j] + dp[i^j]);
		}
	}

	cout << dp[(1 << n) -1] << "\n";
}
