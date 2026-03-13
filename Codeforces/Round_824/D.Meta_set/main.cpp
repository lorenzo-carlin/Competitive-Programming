#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main()
{
	int n, k; cin >> n >> k;
	vector<vector<int>> v(n, vector<int> (k));
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < k; ++j)
		{
			cin >> v[i][j];
		}
	}

	auto complementare = [&](int i, int j) -> vector<int> 
	{
		vector<int> ans(k);
		for(int x = 0; x < k; ++x)
		{
			ans[x] = (6 - v[i][x] - v[j][x]) % 3;
		}
		return ans;
	};

	map<vector<int>,int> mp;
	for(int i = 0; i < n; ++i)
	{
		for(int j = i+1; j < n; ++j)
		{
			mp[complementare(i,j)]++;
		}
	}

	ll ans = 0;
	for(int i = 0; i < n; ++i)
	{
		ll tmp = mp[v[i]];
		ans += (tmp * (tmp-1) / 2);
	}

	cout << ans << "\n";
}
