#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<array<int,3>> v(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i][1] >> v[i][2];
		v[i][0] = v[i][1] + v[i][2];
	}
	sort(begin(v), end(v));
	for(int i = 0; i < n; ++i)
	{
		cout << v[i][1] << " " << v[i][2] << " ";
	}
	cout << "\n";
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
