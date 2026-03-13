#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, p; cin >> n >> p;
	vector<ll> v(n);
	for(auto &i: v) cin >> i;

	ll ans = 0;
	for(int i = 0; i < n; ++i)
	{
		ll tmp = v[i]-p;
		ll D = i;
		ll d = upper_bound(begin(v), end(v), tmp) - begin(v);
		ans += (D - d);
	}

	cout << ans << "\n";
}
