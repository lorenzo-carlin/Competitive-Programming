#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m, a; cin >> n >> m >> a;
	ll ans = 0;
	for(ll i = 1; i*i <= a; i++)
	{
		if(a % i != 0) continue;

		ll x = i, y = a/i;
		if(x >= n && y >= m) ans++;
		if(y >= n && x >= m) ans++;
		if(x == y && x >= n) ans--;
	}

	cout << ans << "\n";
}		
