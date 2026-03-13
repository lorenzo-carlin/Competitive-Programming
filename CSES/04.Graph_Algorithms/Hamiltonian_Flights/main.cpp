#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = (ll)1e9+7;
const int MAXN = 20;
ll dp[1<<MAXN][MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	vector<vector<int>> adj_rev(n);
	for(int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		a--; b--;
		adj_rev[b].push_back(a);
	}

	dp[1][0] = 1;

	for(int i = 2; i < (1 << n); ++i)
	{
		if(i & 1 == 0) continue;
		if((i & (1 << n-1)) && i != ((1 << n)-1)) continue;

		for(int j = 0; j < n; ++j)
		{
			if((i & (1 << j)) == 0) continue;

			int p = i - (1 << j);
			ll sol = 0;
			for(int u: adj_rev[j])
			{
				if((i & (1 << u)) == 0) continue;
				sol += dp[p][u];
				sol %= mod;
			}
			dp[i][j] = sol;
		}
	}

	cout << dp[(1 << n)-1][n-1] << "\n";
}
