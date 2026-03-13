#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	ll n; cin >> n;
	vector<ll> v(n);
	for(auto &i: v) cin >> i;

	vector<ll> cnt(30, 0);
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < 30; ++j)
		{
			if(v[i] & (1 << j))
			{
				cnt[j]++;
			}
		}
	}

	ll mx = 0;
	for(int i = 0; i < n; ++i)
	{
		ll cur = 0;
		for(int j = 0; j < 30; ++j)
		{
			ll t = (1 << j);
			if(v[i] & t)
			{
				cur += (n-cnt[j])*t;
			} else
			{
				cur += cnt[j]*t;
			}
		}
		mx = max(mx, cur);
	}

	cout << mx << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
