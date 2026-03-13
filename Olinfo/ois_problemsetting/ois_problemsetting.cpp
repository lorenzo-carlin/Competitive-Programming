#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool possible(ll k, vector<ll> a, vector<ll> b)
{
	for(int i = 0; i < b.size(); ++i)
	{
		ll c = max(0LL, k-a[i]);
		if(c > b[i]) return false;
		a[i] += c;
		b[i] -= c;
		a[i+1] += b[i];
	}
	if(a.back() < k) return false;
	return true;
}

void solve()
{
	int n; cin >> n;
	vector<ll> a(n), b(n-1);
	for(auto &i: a) cin >> i;
	for(auto &i: b) cin >> i;

	ll mn = min(a[0]+b[0], a.back()+b.back());
	for(int i = 1; i < n-1; ++i)
	{
		mn = min(mn, a[i]+b[i]+b[i-1]);
	}

	ll l = 0, r = mn;
	while(l < r)
	{
		ll m = (l + r) / 2;
		if(possible(m, a, b))
		{
			l = m+1;
		} else
		{
			r = m;
		}
	}

	if(possible(r, a, b)) cout << r << "\n";
	else cout << r-1 << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
