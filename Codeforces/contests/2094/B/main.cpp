#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n, m, l, r; cin >> n >> m >> l >> r;
	int dif = n-m;
	int dx = min(r, dif);
	r -= dx;
	dif -= dx;
	l += dif;
	cout << l << " " << r << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
