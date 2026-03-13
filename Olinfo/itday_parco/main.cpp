#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll visita(int n, int x, int t, vector<int> k, vector<vector<int>> w, vector<vector<int>> f)
{
	t -= x;

	vector<ll> ans(t+1, 0);

	for(int area = 0; area < n; ++area)
	{
		vector<ll> old(t+1, 0), dp(t+1, 0);
		for(int i = 1; i <= k[area]; ++i)
		{
			swap(old, dp);
			dp.resize(t+1, 0);
			for(int j = 1; j <= t; ++j)
			{
				// non prendo nulla
				dp[j] = old[j];
				// prendo ma rimango nella mia area
				if(j - w[area][i-1] >= 0)
				{
					dp[j] = max(dp[j], old[j-w[area][i-1]]+f[area][i-1]);
				}
				// prendo e cambio area
				if(j - w[area][i-1] - x >= 0)
				{
					dp[j] = max(dp[j], ans[j-w[area][i-1]-x]+f[area][i-1]);
				}
			}
		}
		for(int j = 1; j <= t; ++j)
		{
			ans[j] = max(ans[j], dp[j]);
		}
	}

	return ans[t];
}
