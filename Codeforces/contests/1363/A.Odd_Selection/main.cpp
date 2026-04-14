#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n, x; cin >> n >> x;
	int odd = 0, even = 0;
	for(int i = 0, c; i < n; ++i)
	{
		cin >> c;
		if(c % 2) odd++;
		else even++;
	}

	if(x == n)
	{
		if(odd % 2) cout << "Yes\n";
		else cout << "No\n";
	} else
	{
		if(x % 2 && odd) cout << "Yes\n";
		else if(x % 2) cout << "No\n";
		else if(x % 2 == 0 && even) cout << "Yes\n";
		else cout << "No\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
