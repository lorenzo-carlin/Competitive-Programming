#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	int k = 0, mx = 0;
	while((1 << k) <= n)
	{
		if(n & (1 << k))
		{
			mx = k;
		}
		k++;
	}
	cout << (1 << mx) - 1 << "\n";
}			

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
