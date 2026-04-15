#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll mod = 1e9+7;

void solve()
{
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(auto &i: a) cin >> i;
	for(auto &i: b) cin >> i;
	sort(begin(a), end(a));
	sort(begin(b), end(b));

	ll ans = 1;
	int idx = 0;
	for(int i = 0; i < n; ++i)
	{
		while(idx != n && b[idx] < a[i]) idx++;
		ans *= (idx-i);
		ans %= mod;
	}

	cout << ans << "\n";
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
