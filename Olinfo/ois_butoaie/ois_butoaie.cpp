#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k; cin >> n >> k;
	int p, q; cin >> p >> q;
	int mx, mn, mx_ind, mn_ind;
	if(p > q)
	{
		mx = p;
		mx_ind = k;
		mn = q;
		mn_ind = n-k;
	} else
	{
		mx = q;
		mx_ind = n-k;
		mn = p;
		mn_ind = k;
	}
	vector<int> v(n);
	for(auto &i: v) cin >> i;

	auto possible = [&] (int val) -> bool
	{
		int tot = 0;
		for(int i = 0; i < n; i++)
		{
			tot += (v[i] - mn*val + mx - mn - 1) / (mx - mn);
		}
		if(tot > val*mx_ind) return false;
		else return true;
	};

	int l = 0, r = 1e9;
	while(l < r)
	{
		int m = (l + r) / 2;
		if(possible(m))
		{
			r = m;
		} else
		{
			l = m+1;
		}
	}

	if(possible(r-1)) cout << r-1 << "\n";
	else cout << r << "\n";
}
