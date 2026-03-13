#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	ll n, m; cin >> n >> m;
	vector<pair<ll,ll>> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i].first;
	for(int i = 0; i < n; ++i) cin >> v[i].second;
	sort(begin(v), end(v));
	v.push_back({1e18+5, 0});
	vector<pair<ll,ll>> cop = v;

	ll mx = 0;
	for(int i = 0; i < n; i++)
	{
		if(v[i].first*v[i].second <= m)
		{
			mx = max(mx, v[i].first*v[i].second);
		} else
		{
			mx = max(mx, m - (m % v[i].first));
		}
	}

	// 1  2  3  4  5  11
	// 2  2  2  2  1  1

	for(int i = 0; i < n; i++)
	{
		v[i].second = cop[i].second;
		v[i+1].second = cop[i+1].second;
		if(v[i+1].first - v[i].first <= 1)
		{
			ll tmp = v[i].first*v[i].second + v[i+1].first*v[i+1].second;
			if(tmp <= m)
			{
				mx = max(mx, tmp);
			} else
			{
				ll a = min(m / v[i].first, v[i].second); // 3
				ll rem = m - (a*v[i].first); // 415
				ll b = min(rem / v[i+1].first, v[i+1].second); // 2
				v[i+1].second -= b; // 2
				rem -= (b*v[i+1].first); // 1
				ll agg = min(rem, min(v[i+1].second, v[i].second)); // 1
				b += agg;
				a -= agg;
				mx = max(mx, a*v[i].first+b*v[i+1].first);
			}
		}
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
