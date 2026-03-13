#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 1e9+7;
constexpr int MAXN = 2e6+5;

ll fact[MAXN];

ll fast_exp(ll base, ll exp)
{
	if(exp == 0) return 1;
	if(exp == 1) return base;

	ll ans = fast_exp(base, exp/2);
	ans = ans*ans;
	ans %= mod;

	if(exp&1) ans = ans*base;
	ans %= mod;

	return ans;
}

ll mod_inv(ll a)
{
	return fast_exp(a, mod-2);
}

void precalculate()
{
	fact[0] = 1;
	for(int i = 1; i < MAXN; ++i)
	{
		fact[i] = fact[i-1]*i;
		fact[i] %= mod;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	precalculate();

	int n, m; cin >> n >> m;
	n--;

	ll ans = fact[n+m] * mod_inv((fact[n]*fact[m])%mod) % mod;

	cout << ans << "\n";
}
