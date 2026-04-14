#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	for(int i = 0; i < n-1; ++i)
	{
		if(i % 2) cout << 3 << " ";
		else cout << -1 << " ";
	}
	if(n % 2) cout << -1 << "\n";
	else cout << 2 << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
