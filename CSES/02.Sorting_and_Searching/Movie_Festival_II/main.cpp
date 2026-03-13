#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k; cin >> n >> k;
	vector<pair<int,int>> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i].second >> v[i].first;
	sort(begin(v), end(v));
	multiset<int> s;
	for(int i = 0; i < k; ++i) s.insert(0);

	int ans = 0;
	for(int i = 0; i < n; ++i)
	{
		auto it = s.upper_bound(v[i].second);
		if(it == begin(s)) continue;
		s.erase(--it);
		s.insert(v[i].first);
		ans++;
	}

	cout << ans << "\n";
}
