#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;
	int n = a.size(), m = b.size();

	int dp[n+1][m+1];

	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j <= m; ++j)
		{
			if(i == 0) dp[i][j] = j;
			if(j == 0) dp[i][j] = i;
			if(i == 0 || j == 0) continue;

			dp[i][j] = 1e9;			
			if(a[i-1] == b[j-1]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
			dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
			dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
			dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
		}
	}

	int ls = dp[n][m];
	cout << ls << "\n";
}
