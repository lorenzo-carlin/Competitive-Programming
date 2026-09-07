#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	ll mat[n][n];

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cin >> mat[i][j];
		}
	}

	vector<ll> dp(1 << n, 0);
	for(int i = 0; i < (1 << n); ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			for(int k = 0; k < j; ++k)
			{
				if((i & (1 << j)) && (i & (1 << k)))
				{
					dp[i] += mat[j][k];
				}
			}
		}
	}

	for(int i = 0; i < (1 << n); ++i)
	{
		for(int j = i; j > 0; j = (j-1) & i)
		{
			dp[i] = max(dp[i], dp[j] + dp[i ^ j]);
		}
	}

	cout << dp[(1 << n) - 1] << "\n";
}
