#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n, k; cin >> n >> k;
	string s; cin >> s;
	vector<int> v(n);
	for(auto &i: v) cin >> i;

	auto possible = [&] (int val) -> bool
	{
		// cout << "possible " << val << "\n";
		int cnt = 0;
		bool cond = false;
		for(int i = 0; i < n; ++i)
		{
			if((s[i] == 'B' && (cond || v[i] > val)) || (s[i] == 'R' && v[i] <= val && cond))
			{
				if(cond == false)
				{
					cnt++;
				}
				cond = true;
			} else
			{
				cond = false;
			}
			// cout << i << ": " << cnt << "\n";
		}
		return (cnt <= k);
	};

	int l = 0, r = *max_element(begin(v), end(v));
	while(l < r)
	{
		int m = (l + r) / 2;
		if(possible(m))
			r = m;
		else
			l = m+1;
	}

	//cout << l << " " << r << "\n";
	if(possible(l))
		cout << l << "\n";
	else
		cout << l-1 << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
