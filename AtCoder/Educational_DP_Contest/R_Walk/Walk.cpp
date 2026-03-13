#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vvll vector<vector<ll>>

ll n, k;
constexpr ll mod = 1e9+7;

vvll multiplication(vvll a, vvll b)
{
	vvll ans(n, vector<ll>(n, 0));
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			for(int k = 0; k < n; ++k)
			{
				ans[i][j] += (a[i][k] * b[k][j]);
				ans[i][j] %= mod;
			}
		}
	}
	return ans;
}

vvll binary_exp(vvll base, ll exp)
{
	if(exp == 1) return base;
	vvll ans = binary_exp(base, exp/2);
	ans = multiplication(ans, ans);
	if(exp & 1) ans = multiplication(ans, base);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	vvll G(n, vector<ll> (n));
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cin >> G[i][j];
		}
	}

	vvll sol = binary_exp(G, k);

	ll tot = 0;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			tot += sol[i][j];
			tot %= mod;
		}
	}

	cout << tot << "\n";
}
