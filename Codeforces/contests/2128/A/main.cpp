#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	ll n, c; cin >> n >> c;
	vector<ll> v(n);
	for(auto &i: v) cin >> i;

	sort(rbegin(v), rend(v));

	int ans = 0, cnt = 0;
	for(int i = 0; i < n; ++i)
	{
		if(v[i] * (1 << cnt) <= c)
		{
			ans++;
			cnt++;
		}
	}

	cout << n-ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
