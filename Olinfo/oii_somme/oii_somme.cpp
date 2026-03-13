#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1e18;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<ll> v(n);
	for(auto &i: v) cin >> i;
	vector<ll> ps(n+1, 0);
	for(int i = 1; i <= n; ++i) ps[i] = ps[i-1]+v[i-1];

	vector<vector<ll>> dp(n, vector<ll> (n, INF));
	for(int i = 0; i < n; ++i)
	{
		dp[i][i] = 0;
	}
	for(int i = 0; i < n-1; ++i)
	{
		dp[i][i+1] = abs(v[i]+v[i+1]);
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = i+2; j < n; ++j)
		{
			for(int x = i; x < j; x++)
			{
				dp[i][j] = min(dp[i][j], max(dp[i][x], dp[x+1][j]));
			}
			dp[i][j] = max(dp[i][j], abs(ps[j+1]-ps[i]));
		}
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(j < i) cout << "-\t";
			else cout << dp[i][j] << "\t";
		}
		cout << "\n";
	}

	cout << dp[0][n-1] << "\n";
}
