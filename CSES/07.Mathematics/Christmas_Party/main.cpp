#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 1e9+7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	ll tmp = 1;
	ll ans = (n & 1) ? (-1) : (1);
	for(int i = 0; i < n; i++)
	{
		int pr = n-i;
		tmp *= pr;
		tmp %= mod;
		if(pr % 2 == 0)
		{
			ans += mod;
			ans -= (tmp % mod);
			ans %= mod;
		} else
		{
			ans += (tmp % mod);
			ans %= mod;
		}
	}

	cout << ans << "\n";
	return 0;
}
