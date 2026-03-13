#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);

	for(auto &i: a) cin >> i;
	for(auto &i: b) cin >> i;
	sort(begin(a), end(a));
	sort(begin(b), end(b));

	ll ans = 0;
	int lA = 0, lB = 0, rA = n-1, rB = m-1;
	for(int i = 0; i < n; ++i)
	{
		int x = abs(a[lA]-b[lB]);
		int y = abs(a[lA]-b[rB]);
		int w = abs(a[rA]-b[lB]);
		int z = abs(a[rA]-b[rB]);

		if(x >= y && x >= w && x >= z)
		{
			ans += x;
			lA++;
			lB++;
		} else if(y >= x && y >= w && y >= z)
		{
			ans += y;
			lA++;
			rB--;
		} else if(w >= x && w >= y && w >= x)
		{
			ans += w;
			rA--;
			lB++;
		} else if(z >= x && z >= y && z >= w)
		{
			ans += z;
			rA--;
			rB--;
		}
	}
	cout << ans << "\n";
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
