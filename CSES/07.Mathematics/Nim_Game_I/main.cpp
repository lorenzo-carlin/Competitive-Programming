#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	int ans = 0;
	for(int i = 0, a; i < n; ++i)
	{
		cin >> a;
		ans ^= a;
	}

	if(ans) cout << "first\n";
	else cout << "second\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
