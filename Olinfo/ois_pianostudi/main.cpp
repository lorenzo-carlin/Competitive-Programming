#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; cin >> n;
	vector<array<int,3>> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i][0] >> v[i][1] >> v[i][2];
	sort(v.rbegin(), v.rend());

	map<int,int> dp;

	auto solve = [&] (int i) -> int
	{
		auto it = dp.lower_bound(i);
		return (*it).second;
	};

	dp[1e9] = 0;
	for(int i = 0; i < n; ++i)
	{
		dp[v[i][0]] = solve(v[i][0]);
		dp[v[i][0]] = max(dp[v[i][0]], solve(v[i][1]+1)+v[i][2]);
	}

	cout << solve(0) << "\n";
}
