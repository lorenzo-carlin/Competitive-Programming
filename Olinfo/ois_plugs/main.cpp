#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	vector<pair<int,string>> v(n);
	map<string,int> mp;

	for(int i = 0; i < n; ++i)
	{
		cin >> v[i].first;
	}
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i].second;
	}
	sort(rbegin(v), rend(v));

	for(int i = 0; i < m; ++i)
	{
		string s; cin >> s;
		mp[s]++;
	}

	int ans = 0;
	for(int i = 0; i < n; ++i)
	{
		if(mp[v[i].second] > 0)
		{
			mp[v[i].second]--;
			ans += v[i].first;
		} else if(mp["bipasso"] > 0)
		{
			mp["bipasso"]--;
			ans += v[i].first;
		}
	}

	cout << ans << "\n";
}
