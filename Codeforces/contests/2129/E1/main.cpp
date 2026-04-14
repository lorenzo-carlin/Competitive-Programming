#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;

	// cerco il primo valore tale che f(x1...xp) = 1
	int l = 0, r = n-1;
	while(l < r)
	{
		int m = (l + r) / 2;
		if(f(m)) r = m;
		else l = m+1;
	}
	// parentesi chiusa e aperta
	int ap = l-1, ch = l;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
