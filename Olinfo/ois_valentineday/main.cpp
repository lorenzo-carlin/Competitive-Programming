#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	vector<int> a(n), b(n);
	for(auto &i: a) cin >> i;
	for(auto &i: b) cin >> i;

	int ans = 0;
	for(int i = 0; i < n; ++i)
	{
		if(!(a[i] & 1) && b[i] <= m)
		{
			ans = max(ans, a[i]);
		}
	}

	cout << ans << "\n";
}
