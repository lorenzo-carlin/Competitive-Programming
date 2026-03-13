#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b)
{
	if(b == 0) return a;
	else return gcd(b, a%b);
}

void solve()
{
	ll a, b, k; cin >> a >> b >> k;
	ll GCD = gcd(a, b);
	if((a/GCD) <= k && (b/GCD) <= k) cout << 1 << "\n";
	else cout << 2 << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
