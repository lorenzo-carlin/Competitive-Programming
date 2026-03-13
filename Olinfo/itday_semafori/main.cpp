#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int traffico(int n, vector<int> s)
{
	int dp[n+1][2];
	dp[n][0] = dp[n][1] = 0;
	for(int i = n-1; i >= 0; i--)
	{
		if(s[i] & 1)
		{
			dp[i][1] = dp[i+1][0];
			dp[i][0] = dp[i+1][1]+1;
		} else
		{
			dp[i][0] = dp[i+1][1];
			dp[i][1] = dp[i+1][0]+1;
		}
	}

	return min(dp[0][0], dp[0][1]);
}
