#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	ll n, m; cin >> n >> m;
	vector<ll> v(n);
	for(auto &i: v) cin >> i;
	sort(begin(v), end(v));

	ll mx = 0, tot = 0;
	int l = 0, r = 0;
	for(; l < n; l++)
	{
		while(r < n && tot + v[r] <= m && v[r]-v[l] <= 1)
		{
			tot += v[r];
			r++;

			mx = max(mx, tot);
		}

		tot -= v[l];
	}

	cout << mx << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
