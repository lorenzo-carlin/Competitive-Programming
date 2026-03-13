#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int LOG = 32;

ll riciclo(int n, int m, vector<int> t, vector<int> p)
{
	vector<ll> bit(32, 0), P(32, 0);
	for(int i = 0; i < m; ++i) P[i] = (ll)p[i];
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < 32; ++j)
		{
			ll tmp = 1 << j;
			if(((ll)t[i]) & tmp)
			{
				bit[j]++;
			}
		}
	}

	ll sol = 0;
	for(int i = 0; i < 32; ++i)
	{
		int ind = i;
		while(ind < 32 && P[i])
		{
			ll bitcheuso = min(P[i], bit[ind] << (ind-i));
			sol += bitcheuso;
			P[i] -= bitcheuso;

			ll rimanenti = (bit[ind] << ind) - (bitcheuso << i);
			bit[ind] = 0;
			for(int j = 0; rimanenti > 0 && j < ind; ++j, rimanenti >>= 1)
			{
				if(rimanenti & 1) bit[j]++;
			}
			bit[ind] += rimanenti;

			ind++;
		}
	}

	return sol;
}
