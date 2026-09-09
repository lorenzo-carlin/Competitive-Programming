#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> v(n);
	map<int,multiset<int>> mp;
	for(int i = 0; i < n; ++i) cin >> v[i];

	int ans = 0;
	for(int i = 0; i < n; ++i)
	{
		int t = v[i];
		if(mp[v[i]-2].empty())
		{
			ans++;
		} else
		{
			t = *mp[v[i]-2].begin();
			mp[v[i]-2].erase(mp[v[i]-2].begin());
		}

		if(t != -v[i])
		{
			mp[v[i]].insert(t);
		}
	}

	bool possible = true;
	for(auto el: mp)
	{
		if(!el.second.empty())
		{
			possible = false;
		}
	}

	if(!possible)
	{
		cout << 0 << "\n";
	} else
	{
		cout << ans << "\n";
	}
}
