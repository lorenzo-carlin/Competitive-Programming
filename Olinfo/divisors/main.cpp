#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll compute(ll n)
{
	ll ans = 0;
	ll rad = sqrt(n);
	for(ll i = 1; i <= rad; i++)
	{
		ll j = (n/i);
		ll k = ((n/i) - (n/(i+1)))*i;
		if((n/i) - (n/(i+1)) == 1 && j == k) ans += j;
		else ans += (j + k);
	}
	return ans;
}
