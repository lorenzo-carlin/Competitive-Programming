#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 1e6+5;

void solve()
{
	int n; cin >> n;
	bitset<MAXN> bit;
	string s; cin >> s;
	for(int i = 0; i < n; ++i) bit[i] = (s[i] == '0') ? (0) : (1);

	vector<ll> cost(n);
	for(int i = n; i >= 1; i--)
	{
		for(int j = i; j <= n; j += i)
		{
			if(bit[j-1]) break;
			cost[j-1] = i;
		}
	}

	ll ans = 0;
	for(int i = 0; i < n; ++i)
	{
		if(!bit[i])
		{
			ans += cost[i];
		}
	}

	cout << ans << "\n";
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
