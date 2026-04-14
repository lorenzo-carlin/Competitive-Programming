#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(auto &i: a) cin >> i;
	for(auto &i: b) cin >> i;

	int tot = 0;
	for(int i = 0; i < n; ++i)
	{
		if(b[i] >= a[i]) continue;
		tot += (a[i] - b[i]);
	}

	cout << tot+1 << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
