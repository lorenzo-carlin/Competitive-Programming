#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, p, k; cin >> n >> p >> k;
	vector<ll> a(n);
	for(auto &i: a) cin >> i;

	vector<ll> idx(n);
	iota(begin(idx), end(idx), 0);
	sort(begin(idx), end(idx), [&](ll x, ll y) {
		return a[x] > a[y];
	});

	vector<vector<ll>> mat(n, vector<ll> (p));
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < p; ++j)
		{
			cin >> mat[i][j];
		}
	}

	vector<vector<ll>> dp(n+1, vector<ll> ((1 << p), -1));
	dp[0][0] = 0;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; j < (1 << p); ++j)
		{
			// aggiungo l'(i-1)-esima persona alla squadra
			for(int z = 0; z < p; ++z)
			{
				if(j & (1 << z))
				{
					if(dp[i-1][j^(1 << z)] == -1) continue;
					dp[i][j] = max(dp[i][j], dp[i-1][j^(1 << z)] + mat[idx[i-1]][z]);
				}
			}

			int on = __builtin_popcount(j);
			// non aggiungo l'(i-1)-esima persona alla squadra
			// i bit accesi sono < k, quindi devo ancora selezionare pubblico
			if(i-1-on < k)
			{
				if(dp[i-1][j] == -1) continue;
				dp[i][j] = max(dp[i][j], dp[i-1][j] + a[idx[i-1]]);
			} else
			// i bit accesi sono >= k, quindi ho già selezionato il pubblico
			{
				if(dp[i-1][j] == -1) continue;
				dp[i][j] = max(dp[i][j], dp[i-1][j]);
			}
		}
	}

	cout << dp[n][(1 << p)-1] << "\n";
}
