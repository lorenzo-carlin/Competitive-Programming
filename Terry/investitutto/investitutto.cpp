#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t; cin >> t;
	for(int x = 1; x <= t; ++x)
	{
		int n; cin >> n;
		vector<ll> v(n), g(n);
		for(auto &i: v) cin >> i;
		for(auto &i: g) cin >> i;

		vector<bool> pos(n, false);
		pos[0] = true;
		for(int i = 1; i < n; ++i)
		{
			for(int j = 0; j < i; ++j)
			{
				if(v[j] + (i-j)*g[j] >= v[i] && pos[j])
				{
					pos[i] = true;
					break;
				}
			}
		}

		ll ans = 0;
		for(int i = 0; i < n; ++i)
		{
			if(pos[i])
			{
				ans = max(ans, v[i] + g[i]*(n-i));
			}
		}

		cout << "Case #" << x << ": " << ans << "\n";
	}
}
