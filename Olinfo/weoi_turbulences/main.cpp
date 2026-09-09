#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll revenue(int n, int k, vector<ll> a)
{
	set<ll> abs_values;
	for(int i = 0; i < n; ++i)
	{
		abs_values.insert(abs(a[i]));
	}

	vector<ll> pos, neg;
	for(int i = 0; i < n; ++i)
	{
		if(a[i] > 0) pos.push_back(a[i]);
		else if(a[i] < 0) neg.push_back(-a[i]);
	}
	sort(begin(pos), end(pos));
	sort(begin(neg), end(neg));

	vector<ll> psPos, psNeg;
	psPos.push_back(0);
	psNeg.push_back(0);
	for(int i = 0; i < pos.size(); ++i) psPos.push_back(psPos[i] + pos[i]);
	for(int i = 0; i < neg.size(); ++i) psNeg.push_back(psNeg[i] + neg[i]);

	auto cnt = [&](ll val) -> ll
	{
		int indPos = lower_bound(begin(pos), end(pos), val) - begin(pos);
		int indNeg = lower_bound(begin(neg), end(neg), val) - begin(neg);
		ll sumPos = psPos[indPos] - psPos[0] + val*(pos.size()-indPos);
		ll sumNeg = psNeg[indNeg] - psNeg[0] + val*(neg.size()-indNeg);
		ll tot = sumPos-sumNeg-(k*val);
		return tot;
	};

	ll mx = 0;
	for(auto el: abs_values)
	{
		mx = max(mx, cnt(el));
	}

	return mx;
}
