#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	ll n, x, k; cin >> n >> x >> k;
	string s; cin >> s;

	ll t1 = -1, t2 = -1;

	int ind = 0;
	for(int i = 0; i < n; ++i)
	{
		if(s[i] == 'R') ind++;
		else ind--;

		if(ind == 0)
		{
			t1 = i+1;
			break;
		}
	}

	ind = x;
	for(int i = 0; i < n; ++i)
	{
		if(s[i] == 'R') ind++;
		else ind--;

		if(ind == 0)
		{
			t2 = i+1;
			break;
		}
	}

	if(t2 == -1)
	{
		cout << 0 << "\n";
		return;
	}

	ll ans = 0;
	k -= t2;
	if(k >= 0)
	{
		ans++;
		if(t1 != -1) ans += (k / t1);
	}

	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
