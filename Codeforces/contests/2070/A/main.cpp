#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	ll ans = (n/15) + ((n-1)/15) + ((n-2)/15);
	if(n >= 0) ans++;
	if(n >= 1) ans++;
	if(n >= 2) ans++;
	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
