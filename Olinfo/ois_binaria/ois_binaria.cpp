#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	vector<ll> pot(61, 1);
	for(int i = 1; i < 61; ++i) pot[i] = 2*pot[i-1];
	for(int i = 0; i < 61; ++i) pot[i]--;
	
	int n; cin >> n;
	ll ans = 0;
	for(int i = 0; i < n; ++i)
	{
		ll a; cin >> a;
		auto it = lower_bound(begin(pot), end(pot), a);
		ans += (*it - a);
	}

	cout << ans << "\n";
}
