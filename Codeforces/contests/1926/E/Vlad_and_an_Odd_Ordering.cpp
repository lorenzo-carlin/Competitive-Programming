#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> pot(33);

void precalculate()
{
	pot[0] = 1;
	for(int i = 1; i < 33; ++i)
	{
		pot[i] = pot[i-1]*2;
	}
}

void solve()
{
	ll n, k; cin >> n >> k;

	ll rem = n;

	ll ind = 1;
	while(k > ((rem+1)/2))
	{
		k -= ((rem+1)/2);
		rem -= ((rem+1)/2);
		ind++;
	}

	ll ans = pot[ind-1] + pot[ind]*(k-1);
	cout << ans << "\n";
}

int main()
{
	precalculate();

	int t; cin >> t;
	while(t--) solve();
}

