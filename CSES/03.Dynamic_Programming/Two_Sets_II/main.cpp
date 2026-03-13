#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 505;
constexpr int MAXM = 505*504/2;
constexpr int mod = 1e9+7;

int dp[MAXN][MAXM];
bool memo[MAXN][MAXM];

int solve(int i, int j)
{
	if(i == 0) return 0;
	if(j == 0) return 1;

	if(memo[i][j]) return dp[i][j];
	memo[i][j] = true;

	int ans = solve(i-1, j-i) + solve(i-1, j);
	ans %= mod;

	return dp[i][j] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	ll sum = n*(n+1)/2;

	if(sum & 1) cout << 0 << "\n";	// se sum è dispari
	else cout << solve(n, sum/2) << "\n";
}
