#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(auto &i: a) cin >> i;
	for(auto &i: b) cin >> i;

	vector<bool> pos(n, false);
	if(a[n-1] == b[n-1]) pos[n-1] = true;
	for(int i = n-2; i >= 0; i--)
	{
		int x = (a[i] ^ a[i+1]);
		int y = (a[i] ^ b[i+1]);
		if(x == b[i] || y == b[i] || a[i] == b[i])
		{
			pos[i] = true;
		}
	}

	bool possible = true;
	for(int i = 0; i < n; ++i)
	{
		if(!pos[i])
		{
			possible = false;
		}
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
