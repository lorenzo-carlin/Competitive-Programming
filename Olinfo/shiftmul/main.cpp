#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9+7;

ll MCD(ll n, ll d)
{
	if(d == 0) return n;
	else return MCD(d, n%d);
}

ll fast_exp(ll base, ll exp)
{
	if(exp == 0) return 1;
	if(exp == 1) return base % MOD;
	ll ans = fast_exp(base, exp/2);
	ans = (ans * ans) % MOD;
	if(exp & 1) ans = (ans * base) % MOD;
	return ans;
}

ll inv_mod(ll n)
{
	return fast_exp(n, MOD-2);
}

vector<int> execute(int n, int k, int d, vector<int> a)
{
	ll cycles = MCD(n, d);		// nr di cicli
	ll length = n/cycles;		// lunghezza di ogni ciclo
	ll repetitions = k/length;	// nr di ripetizioni di ogni ciclo
	ll rem = k % length;		// iterazioni rimanenti

	vector<ll> sol(n);

	// CREO UN VETTORE PER OGNI CICLO
	vector<vector<ll>> v(cycles);
	for(ll i = 0; i < n; ++i)
	{
		v[i%cycles].push_back(a[i]);
	}

	// ASSEGNO AD OGNI ELEMENTO (IL PRODOTTO DEL SUO CICLO) ^ RIPETIZIONI
	for(ll i = 0; i < cycles; ++i)
	{
		ll pr = 1;
		for(ll el: v[i])
		{
			pr = (pr * el) % MOD;
		}
		ll tmp = fast_exp(pr, repetitions);
		for(ll j = i; j < n; j += cycles)
		{
			sol[j] = tmp;
		}
	}

	vector<bool> vis(n, false);
	for(ll i = 0; i < n; ++i)
	{
		if(!vis[i])
		{
			ll l = i, r = i;
			ll pr = 1;
			ll it = 0;

			while(it < rem)
			{
				pr = (pr * a[r]) % MOD;
				r = (r - d + n) % n;
				it++;
			}

			while(!vis[l])
			{
				vis[l] = true;
				sol[l] = (sol[l] * pr) % MOD;
				
				pr = (pr * a[r]) % MOD;
				pr = (pr * inv_mod(a[l])) % MOD;
				l = (l - d + n) % n;
				r = (r - d + n) % n;
			}
		}
	}

	vector<int> ans(n);
	for(int i = 0; i < n; ++i)
	{
		sol[i] %= MOD;
		ans[i] = sol[i];
	}

	return ans;
}


int main()
{
	int n, k, d; cin >> n >> k >> d;
	vector<int> a(n);
	for(auto &el: a) cin >> el;

	execute(n, k, d, a);

}