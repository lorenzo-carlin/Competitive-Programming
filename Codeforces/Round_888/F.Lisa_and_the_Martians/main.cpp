#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n, k; cin >> n >> k;
	vector<pair<int,int>> v(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(begin(v), end(v));

	auto difference = [&] (int a, int b) -> int
	{
		int ans = 0;
		for(int i = k-1; i >= 0; i--)
		{
			int t = (1 << i);
			if(((a & t) && !(b & t)) || (!(a&t) && (b & t))) ans += t;
		}
		return ans;
	};

	int mn = INT_MAX;
	pair<int,int> c;
	for(int i = 0; i < n-1; ++i)
	{
		int dif = difference(v[i].first, v[i+1].first);
		if(dif < mn)
		{
			mn = dif;
			c = {i, i+1};
		}
	}

	int x = 0;
	for(int i = k-1; i >= 0; i--)
	{
		if((!(v[c.first].first & (1 << i)) && (!(v[c.second].first & (1 << i)))))
		{
			x += (1 << i);
		}
	}

	cout << v[c.first].second+1 << " " << v[c.second].second+1 << " " << x << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
