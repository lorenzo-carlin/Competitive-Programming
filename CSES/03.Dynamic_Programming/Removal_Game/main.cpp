#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1e18;
constexpr int MAXN = 5e3+5;
ll dp[MAXN][MAXN];
bool memo[MAXN][MAXN];
vector<ll> v, ps;

ll solve(int i, int j)
{
	if(memo[i][j]) return dp[i][j];
	if(i == j) return v[i];

	ll rim_il_primo = solve(i+1, j);
	ll rim_l_ultimo = solve(i, j-1);

	memo[i][j] = true;
	return dp[i][j] = (ps[j+1] - ps[i]) - min(rim_il_primo, rim_l_ultimo);
}	

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	v.resize(n);
	ps.resize(n+1, 0);
	for(auto &i: v) cin >> i;

	for(int i = 0; i < n; ++i)
	{
		ps[i+1] = v[i] + ps[i];
	}

	cout << solve(0, n-1) << "\n";
}
