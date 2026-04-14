#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(int &i: a) cin >> i;
	for(int &i: b) cin >> i;

	int ans = a.back();
	for(int i = 0; i < n-1; ++i)
	{
		if(a[i] > b[i+1])
		{
			ans += (a[i] - b[i+1]);
		}
	}

	cout << ans << "\n";
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
