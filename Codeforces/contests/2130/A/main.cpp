#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	int sum = 0, zero = 0, uno = 0;
	for(int i = 0, a; i < n; ++i)
	{
		cin >> a;
		if(a == 0) zero++;
		if(a == 1) uno++;
		sum += a;
	}

	int mn = min(zero, uno);
	int tot = sum + mn;
	uno -= mn;
	zero -= mn;
	tot += zero;

	cout << tot << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
