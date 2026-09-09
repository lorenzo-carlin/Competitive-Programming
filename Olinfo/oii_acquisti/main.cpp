#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> calcola(int t, int m, vector<ll> s, vector<ll> p)
{
	vector<ll> ans(m);

	vector<ll> ps(t), el(t);
	ps[0] = 0, el[0] = s[0];
	for(int i = 1; i < t; ++i)
	{
		el[i] = el[i-1] + s[i];
		ps[i] = ps[i-1] + (s[i]*i);
	}

	for(int i = 0; i < m; ++i)
	{
		ll a = p[i];

		ll l = 0, r = t-1;
		while(l < r)
		{
			int mm = (l + r) / 2;
			if(ps[mm] <= a)
			{
				l = mm+1;
			} else
			{
				r = mm;
			}
		}

		if(a >= ps[t-1]) ans[i] = el[r];
		else
		{
			ll sol = el[r-1] + (a - ps[r-1])/r;
			ans[i] = sol;	
		}
	}

	return ans;
}
