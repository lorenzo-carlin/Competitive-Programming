#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> v(n), p(n), c(n);
	for(auto &i: v) cin >> i;
	for(auto &i: p) cin >> i;
	for(auto &i: c) cin >> i;

	ll g = 0, m = 0, mn = 1e18;
	for(int i = 0; i < n; ++i)
	{
		if(v[i]-p[i] > c[i])
		{
			g += (v[i]-p[i]);
			m -= p[i];
		} else
		{
			g += c[i];
			m += c[i];
		}
		mn = min(mn, m);
	}
	if(mn < 0) mn = -mn;
	else mn = 0;

	cout << g << " " << mn << "\n";
}
