#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	ll n; cin >> n;
	vector<ll> v(n);
	for(auto &i: v) cin >> i;

	ll ans = n*(n+1)*(n+2)/6;
	for(ll i = 0; i < n-1; ++i)
	{
		if(v[i] < v[i+1])
		{
			ans -= (i+1)*(n-i-1);
		}
	}

	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
