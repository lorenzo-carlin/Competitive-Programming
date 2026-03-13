#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<ll> v(n);
	for(auto &i: v) cin >> i;

	vector<pair<ll,ll>> p(n);
	for(int i = 0; i < n; ++i) p[i].first = v[i] + i;
	for(int i = 0; i < n; ++i) p[i].second = p[i].first + i;

	set<ll> s;
	s.insert(n);
	sort(begin(p), end(p));
	for(int i = 0; i < n; ++i)
	{
		if(s.count(p[i].first)) s.insert(p[i].second);
	}

	auto it = s.end();
	it--;
	
	cout << *it << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	while(n--) solve();
}
