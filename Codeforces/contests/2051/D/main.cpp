#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	ll n;
	ll x, y;
	cin >> n >> x >> y;

	vector<ll> v(n);
	for(auto &i: v) cin >> i;
	ll sum = 0;
	for(int i = 0; i < n; ++i) sum += v[i];

	sort(begin(v), end(v));

	ll ans = 0;
	for(int i = 0; i < n; ++i)
	{
		ll mx = sum - x - v[i];
		ll mn = sum - y - v[i];

		if(mx <= 0) continue;

		auto it1 = lower_bound(begin(v), end(v), mn);
		auto it2 = upper_bound(begin(v), end(v), mx); it2--;

		if(it2-it1 < 0) continue;

		ans += (it2-it1+1);

		if(mn <= v[i] && v[i] <= mx) ans--;
	}

	ans /= 2;

	cout << ans << "\n";

}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
