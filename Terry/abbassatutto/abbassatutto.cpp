#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t; cin >> t;
	for(int x = 1; x <= t; x++)
	{
		int n; cin >> n;
		vector<ll> p(n), c(n);
		for(auto &i: p) cin >> i;
		for(auto &i: c) cin >> i;

		ll ans = 0;
		vector<pair<ll,int>> a(n);
		for(int i = 0; i < n; ++i) a[i] = {c[i], i};
		sort(begin(a), end(a));

		vector<ll> ps(n+1, 0);
		for(int i = n-1; i >= 0; i--) ps[i] = ps[i+1] + p[i];

		ll aposto = 0;
		for(int i = 0; i < n; ++i)
		{
			ll cnt = max(ps[a[i].second] - aposto, 0LL);
			ans += (cnt * a[i].first);
			aposto += cnt;			
		}

		cout << "Case #" << x << ": " << ans << "\n";
	}
}
