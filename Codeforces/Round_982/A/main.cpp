#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	int wmax = 0, hmax = 0;
	for(int i = 0, a, b; i < n; ++i)
	{
		cin >> a >> b;
		wmax = max(wmax, a);
		hmax = max(hmax, b);
	}

	cout << 2*(wmax+hmax) << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
