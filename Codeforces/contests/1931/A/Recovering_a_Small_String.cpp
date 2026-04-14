#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n, a, b, c;
	cin >> n;

	n -= 2;
	c = min(26, n);
	n -= c;
	n += 2;

	n -= 1;
	b = min(26, n);
	n -= b;
	n += 1;

	a = n;

	char x, y, z;
	x = 'a' + a - 1;
	y = 'a' + b - 1;
	z = 'a' + c - 1;

	cout << x << y << z << "\n";
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}

