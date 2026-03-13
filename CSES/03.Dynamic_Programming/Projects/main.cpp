#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<array<ll,3>> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i][0] >> v[i][1] >> v[i][2];
	map<ll,vector<int>> projects_per_end;
	for(int i = 0; i < n; ++i) projects_per_end[v[i][1]].push_back(i);

	vector<ll> ind;
	ind.push_back(0);
	for(int i = 0; i < n; ++i)
	{
		ind.push_back(v[i][0]);
		ind.push_back(v[i][1]);
	}

	sort(begin(ind), end(ind));
	ind.erase(unique(begin(ind), end(ind)), end(ind));

	map<ll,ll> mp;
	int sz = ind.size();
	for(int i = 0; i < sz; ++i) mp[ind[i]] = i;

	vector<ll> dp(sz, 0);
	for(int i = 1; i < sz; ++i)
	{
		dp[i] = dp[i-1];
		ll real = ind[i];
		for(int project: projects_per_end[real])
		{
			dp[i] = max(dp[i], dp[mp[v[project][0]]-1]+v[project][2]);
		}
	}

	cout << dp.back() << "\n";
}
