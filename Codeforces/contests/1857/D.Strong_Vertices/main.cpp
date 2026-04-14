#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<ll> a(n), b(n);
	for(auto &i: a) cin >> i;
	for(auto &i: b) cin >> i;

	vector<ll> c(n);
	ll mx = -1e18;
	for(int i = 0; i < n; ++i)
	{
		c[i] = a[i]-b[i];
		mx = max(mx, c[i]);
	}

	vector<int> p;
	for(int i = 0; i < n; ++i)
	{
		if(c[i] == mx) p.push_back(i+1);
	}

	cout << p.size() << "\n";
	for(int el: p) cout << el << " ";
	cout << "\n";
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
