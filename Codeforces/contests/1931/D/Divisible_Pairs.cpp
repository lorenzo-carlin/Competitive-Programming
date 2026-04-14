#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n, x, y; cin >> n >> x >> y;
	map<pair<int,int>,int> m;
	vector<pair<int,int>> v(n);
	for(int i = 0, a; i < n; ++i)
	{
		cin >> a;
		v[i].first = a % x;
		v[i].second = a % y;
		m[v[i]]++;
	}
	ll sol = 0;
	for(int i = 0; i < n; ++i)
	{
		m[v[i]]--;
		int ta = (x - v[i].first) % x;
		int tb = v[i].second;
		sol += m[{ta, tb}];
	}
	cout << sol << "\n";
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}

