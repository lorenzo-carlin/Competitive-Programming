#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	ll a, b, c; cin >> a >> b >> c;
	ll k = a + b + c;

	ll mx = 1;
	for(ll i = 1; i*i <= k; i++)
	{
		if(k % i) continue;

		ll u = k/i;
		ll pr_mul = u*(((a-1) / u)+1);
		if(pr_mul <= a+c)
		{
			cout << u << "\n";;
			return;
		}

		pr_mul = i*(((a-1) / i)+1);
		if(pr_mul <= a+c)
		{
			mx = i;
		}

	}
	cout << mx << "\n";
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
