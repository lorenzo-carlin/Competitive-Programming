#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int a, b, k; cin >> a >> b >> k;
	vector<array<int,2>> edges(k);
	vector<int> degM(a, 0), degF(b, 0);
	for(int i = 0, n; i < k; ++i)
	{
		cin >> n; n--;
		edges[i][0] = n;
		degM[edges[i][0]]++;
	}
	for(int i = 0, n; i < k; ++i)
	{
		cin >> n; n--;
		edges[i][1] = n;
		degF[edges[i][1]]++;
	}

	ll ans = 0;
	for(int i = 0; i < k; ++i)
	{
		ans += (k - degM[edges[i][0]] - degF[edges[i][1]] + 1);
	}
	cout << ans/2 << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
