#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1e18;

ll stalkera(int n, int k, vector<int> s)
{
	vector<ll> ps;
	set<ll> c;
	map<ll,ll> mp;
	ps.push_back(0);
	c.insert(0);
	mp[0] = 0;
	for(int i = 0; i < n; ++i)
	{
		ps.push_back((ll) ps.back() + s[i]);
		mp[ps.back()] = i+1;
		// c.insert(ps.back());
	}

	if(ps.back() <= 0) return ps.back();

	auto possible =  [&](ll val) -> bool
	{
		map<ll,ll> copy = mp;

		ll tmp = 0, rep = k, ind = 0;
		while(rep--)
		{
			auto it = copy.upper_bound(tmp);
			while(it != copy.end() && (*it).second < ind)
			{
				copy.erase(it);
				it = copy.upper_bound(tmp);
			}
			it--;
			ind = (*it).second;

			tmp = (*it).first + val;
		}
		auto it = copy.upper_bound(tmp);
		if(it == copy.end()) return true;
		else return false;
	};

	ll l = -INF, r = INF;
	while(l < r)
	{
		ll m = (l + r) / 2;

		if(possible(m))
		{
			// cout << m << " OK\n";
			r = m;
		} else
		{
			// cout << m << " NO\n";
			l = m+1;
		}
	}

	if(possible(r)) return r;
	else return l;
}
