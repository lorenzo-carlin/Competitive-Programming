#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll mod = 666013;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, k; cin >> n >> k;

	auto fast_exp = [&] (auto fast_exp, ll base, ll exp) -> ll
	{
		if(exp == 0) return 1;
		if(exp == 1) return base;

		ll ans = fast_exp(fast_exp, base, exp/2);
		ans = (ans * ans) % mod;
		if(exp & 1) ans = (ans * base) % mod;

		return ans;
	};
	
	auto mod_inv = [&] (ll num) -> ll
	{
		ll tmp = fast_exp(fast_exp, abs(num), mod-2);
		return -tmp;
	};

	if(k % 2 == 0)
	{
		ll a = (fast_exp(fast_exp, ((1-n) + mod*100000) % mod, k-1) - 1 + mod) % mod;
		ll b = (mod_inv(-n) + mod*100000) % mod;
		ll c = ((n-1) + mod*100000) % mod;

		ll ans = (((a * b) % mod) * c) % mod;
		cout << ans << "\n";
	} else
	{
		ll a = (fast_exp(fast_exp, ((1-n) + mod*100000) % mod, k-1) - 1 + mod) % mod;
		ll b = (mod_inv(-n) + mod*100000) % mod;
		ll c = ((1-n) + mod*100000) % mod;

		ll ans = (((a * b) % mod) * c) % mod;
		cout << ans << "\n";
	}
}
