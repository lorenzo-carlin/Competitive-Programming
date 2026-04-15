#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	ll n; cin >> n;
	ll l = 0, r = 2e9;
	ll ans = 1e18;
	while(l < r)
	{
		ll m = (l + r) / 2;
		ll tmp = n - m*(m-1)/2;
		if(tmp < 0)
		{
			r = m;
		} else
		{
			if(tmp <= m)
			{
				ll a = tmp;
				ll b = m - a;
				ans = min(ans, 2*a+b);
			}
			l = m+1;
		}
	}

	cout << ans << "\n";
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
