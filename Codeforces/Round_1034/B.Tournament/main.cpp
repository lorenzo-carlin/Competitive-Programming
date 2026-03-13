#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n, j, k; cin >> n >> j >> k; j--;
	vector<int> v(n);
	for(auto &i: v) cin >> i;
	int mx = 0, val = v[j];
	for(int el: v) mx = max(mx, el);
	if(k == 1 && val != mx) cout << "NO\n";
	else cout << "YES\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
