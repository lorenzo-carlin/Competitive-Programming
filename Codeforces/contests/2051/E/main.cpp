#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n, k; cin >> n >> k;
	vector<ll> a(n), b(n), idx;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		idx.push_back(a[i]);
	}
	for(int i = 0; i < n; ++i)
	{
		cin >> b[i];
		idx.push_back(b[i]);
	}

	sort(begin(idx), end(idx));
	idx.erase(unique(begin(idx), end(idx)), end(idx));

	ll sz = idx.size();
	map<ll,ll> mp;
	for(int i = 0; i < sz; ++i) mp[idx[i]] = i;

	vector<ll> negative(sz, 0);
	vector<ll> not_buy(sz, 0);
	for(ll el: a) negative[mp[el]]++;
	for(ll el: b) not_buy[mp[el]]++;

	ll ans = 0, people = n, neg = 0;
	for(int i = 0; i < sz; ++i)
	{
		if(neg > k) break;

		ans = max(ans, people*idx[i]);
		neg += negative[i];
		people -= not_buy[i];
	}

	cout << ans << "\n";
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
