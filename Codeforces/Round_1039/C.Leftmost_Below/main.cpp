#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<int> v(n);
	for(auto &i: v) cin >> i;

	bool possible = true;
	int mn = 1e9;

	for(int i = 0; i < n; ++i)
	{
		if(v[i] >= 2*mn)
		{
			possible = false;
		}
		mn = min(mn, v[i]);
	}

	if(possible) cout << "YES\n";
	else cout << "NO\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
