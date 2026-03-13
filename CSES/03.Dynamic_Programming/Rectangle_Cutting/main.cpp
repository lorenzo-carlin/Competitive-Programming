#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b; cin >> a >> b;
	int dp[a+1][b+1];
	for(int i = 1; i <= a; ++i)
	{
		for(int j = 1; j <= b; ++j)
		{
			if(i == j)
			{
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = 1e9;
			for(int x = 1; x < i; ++x)
			{
				dp[i][j] = min(dp[i][j], dp[x][j]+dp[i-x][j]+1);
			}
			for(int y = 1; y < j; ++y)
			{
				dp[i][j] = min(dp[i][j], dp[i][y]+dp[i][j-y]+1);
			}
		}
	}

	cout << dp[a][b] << "\n";
}
