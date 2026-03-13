#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll mod = 1e9+7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	vector<ll> v(n);
	for(ll &i: v) cin >> i;

	vector<vector<ll>> dp(n, vector<ll> (m+1, 0));
	// caso base inizio
	if(v[0] == 0)
	{
		for(int i = 0; i < m+1; ++i)
		{
			dp[0][i] = 1;
		}
	} else
	{
		dp[0][v[0]] = 1;
	}

	for(int i = 1; i < n; ++i)
	{
		if(v[i] == 0)
		{
			for(int j = 1; j <= m; ++j)
			{
				if(j != 1) dp[i][j] += dp[i-1][j-1];
				dp[i][j] += dp[i-1][j];
				if(j != m) dp[i][j] += dp[i-1][j+1];
				dp[i][j] %= mod;
			}
		} else
		{
			if(v[i] != 1) dp[i][v[i]] += dp[i-1][v[i]-1];
			dp[i][v[i]] += dp[i-1][v[i]];
			if(v[i] != m) dp[i][v[i]] += dp[i-1][v[i]+1];
			dp[i][v[i]] %= mod;
		}
	}

	// risposta
	ll ans = 0;
	if(v.back() == 0)
	{
		for(int j = 1; j <= m; ++j)
		{
			ans += dp[n-1][j];
			ans %= mod;
		}
	} else
	{
		ans = dp[n-1][v.back()];
	}

	cout << ans << "\n";
}
