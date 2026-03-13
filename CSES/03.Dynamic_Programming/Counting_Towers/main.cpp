#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
constexpr int mod = 1e9+7;
constexpr int MAXN = 1e6+5;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	ll dp[MAXN][2];
	dp[1][0] = dp[1][1] = 1;
 
	for(int i = 2; i <= 1e6; ++i)
	{
		dp[i][0] = (4*dp[i-1][0] + dp[i-1][1]) % mod;
		dp[i][1] = (dp[i-1][0] + 2*dp[i-1][1]) % mod;
	}
 
	int q; cin >> q;
	while(q--)
	{
		int c; cin >> c;
		cout << (dp[c][0] + dp[c][1]) % mod << "\n";
	}
}
