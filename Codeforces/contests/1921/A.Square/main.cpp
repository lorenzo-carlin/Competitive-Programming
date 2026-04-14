#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int mn_x = 1e9, mx_x = -1e9, mn_y = 1e9, mx_y = -1e9;
	for(int i = 0, a, b; i < 4; ++i)
	{
		cin >> a >> b;
		mn_x = min(mn_x, a);
		mx_x = max(mx_x, a);
		mn_y = min(mn_y, b);
		mx_y = max(mx_y, b);
	}

	int area = (mx_x-mn_x)*(mx_y-mn_y);
	cout << area << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
