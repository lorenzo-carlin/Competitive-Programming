#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n, k; cin >> n >> k;
	int p = 0;
	for(int i = 0; i < n; ++i)
	{
		char c; cin >> c;
		if(c == '1') p++;
	}
	if(p <= k || n < 2*k) cout << "Alice\n";
	else cout << "Bob\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
