#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	ll n; cin >> n;
	ll k = log2(n);
	ll sum = n*(n+1)/2 - ((1 << (k+1)) - 1)/(2-1)*2;
	cout << sum << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
