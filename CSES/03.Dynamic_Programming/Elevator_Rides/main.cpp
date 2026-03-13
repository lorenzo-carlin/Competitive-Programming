#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isMinor(array<int,2> a, array<int,2> b)
{
	if(a[0] < b[0]) return true;
	if(a[0] == b[0] && a[1] < b[1]) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x; cin >> n >> x;
	vector<int> w(n);
	for(auto &i: w) cin >> i;

	vector<array<int,2>> dp(1 << n, {100, 0});
	dp[0] = {0, x};

	for(int i = 1; i < (1 << n); ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(i & (1 << j))
			{
				int submask = i ^ (1 << j);
				if((x - dp[submask][1]) >= w[j])			// aggiungo a un ascensore
				{
					array<int,2> m = {dp[submask][0], dp[submask][1] + w[j]};
					if(isMinor(m, dp[i])) dp[i] = m;
				} else
				{
					array<int,2> m = {dp[submask][0]+1, w[j]};		// nuovo ascensore
					if(isMinor(m, dp[i])) dp[i] = m;
				}
			}
		}
	}

	cout << dp[(1 << n)-1][0] << "\n";
}
