#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<ll> v(n);
	for(auto &i: v) cin >> i;

	ll mn = 0, mx = 0, nmx, nmn;
	for(int i = 0; i < n; ++i)
	{
		if(v[i] >= 0)
		{
			nmx = mx + v[i];
			nmn = mn + v[i];
		} else
		{
			nmx = max(abs(mn + v[i]), mx+v[i]);
			nmn = mn + v[i];
		}

		mn = nmn;
		mx = nmx;
	}

	cout << mx << "\n";
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
