#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n, m; cin >> n >> m;
	vector<vector<ll>> dp(n, vector<ll> (m, 0));
	// dp[i][j] = costo minimo per svuotare a fino alla posizione i+1, usando i primi
	// j elementi di b

	vector<int> a(n), b(m);
	int mx = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	for(int i = 0; i < m; ++i) cin >> b[i];
	if(mx > b[0])
	{
		cout << -1 << "\n";
		return;
	}

	vector<ll> ps(n+1, 0);
	for(int i = 1; i <= n; i++) ps[i] = ps[i-1] + a[i-1];

	auto st_prefix = [&] (int ind, int val) -> int
	{
		int r = ind+1;
		ll t = ps[r]-val;
		int ans = r - (lower_bound(begin(ps), end(ps), t) - begin(ps));
		return ind-ans+1;
	};

	for(int j = 0; j < m; j++)
	{
		for(int i = 0; i < n; i++)
		{
			if(a[i] > b[j])
			{
				dp[i][j] = dp[i][j-1];
				continue;
			}

			int st_pre = st_prefix(i, b[j]);
			if(st_pre == 0) dp[i][j] = (m - (j + 1));
			else dp[i][j] = dp[st_pre-1][j] + (m - (j + 1));

			if(j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1]);
		}
	}
/*
	cout << "\t" << st_prefix(1, 7) << "\n";

	for(int j = 0; j < m; ++j)
	{
		for(int i = 0; i < n; ++i)
		{
			cout << dp[i][j] << "\t";
		}
		cout << "\n";
	}
*/

	cout << dp[n-1][m-1] << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	while(n--) solve();
}
