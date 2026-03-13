#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 1e9+7;

int progetti(int n, int k)
{
	vector<vector<ll>> a(k, vector<ll> (1)), c(k, vector<ll> (k));

	if(k == 2)
	{
		a = {{1}, {1}};
		c = {{1, 1}, {1, 0}};
	} else if(k == 3)
	{
		a = {{2}, {1}, {1}};
		c = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
	} else if(k == 4)
	{
		a = {{4}, {2}, {1}, {1}};
		c = {{1, 1, 1, 1}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}};
	} else if(k == 5)
	{
		a = {{7}, {4}, {2}, {1}, {1}};
		c = {{1, 1, 1, 1, 1}, {1, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 1, 0}};
	}

	auto multiplication = [&] (vector<vector<ll>> x, vector<vector<ll>> y) -> vector<vector<ll>>
	{
		vector<vector<ll>> ans(k, vector<ll> (k, 0));
		for(int i = 0; i < k; ++i)
		{
			for(int j = 0; j < k; ++j)
			{
				for(int d = 0; d < k; ++d)
				{
					ans[i][j] += x[i][d]*y[d][j];
					ans[i][j] %= mod;
				}
			}
		}
		return ans;
	};

	auto fast_exp = [&] (auto fast_exp, vector<vector<ll>> base, int exp) -> vector<vector<ll>>
	{
		if(exp == 1) return base;

		vector<vector<ll>> ans = fast_exp(fast_exp, base, exp/2);
		ans = multiplication(ans, ans);
		if(exp & 1) ans = multiplication(ans, base);

		return ans;
	};

	// elevo la matrice c alla n-1
	vector<vector<ll>> pr = fast_exp(fast_exp, c, n-1);

	// moltiplico a per c elevata alla n-1
	vector<vector<ll>> sol(k, vector<ll> (1));
	for(int i = 0; i < k; ++i)
	{
		for(int d = 0; d < k; ++d)
		{
			sol[i][0] += a[d][0]*pr[i][d];
			sol[i][0] %= mod;
		}
	}

	return sol[k-2][0];
}
