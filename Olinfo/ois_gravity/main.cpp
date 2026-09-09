#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXH = 20005;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	vector<array<int,2>> dp(MAXH, {0, 0});

	int n; cin >> n;
	vector<int> v(n);
	for(auto &i: v) cin >> i;

	int mx, ans = 0;
	for(int i = 0; i < n; i++)
	{
		// ci arrivo da un valore più basso
		mx = 0;
		for(int j = 0; j < v[i]; ++j)
			mx = max(mx, dp[j][1]+1);
		dp[v[i]][0] = mx;
		
		// ci arrivo da un valore più alto
		mx = 0;
		for(int j = 20000; j > v[i]; j--)
			mx = max(mx, dp[j][0]+1);
		dp[v[i]][1] = mx;

		ans = max(ans, dp[v[i]][0]);
		ans = max(ans, dp[v[i]][1]);
	}

	cout << ans << "\n";
}
