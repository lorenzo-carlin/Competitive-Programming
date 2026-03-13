#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> a(n), b(n);
	for(int &i: a) cin >> i;
	for(int &i: b) cin >> i;

	int mn = 1e9;
	ll sol = 0;
	for(int i = 0; i < n; ++i)
	{
		if(a[i] < mn) mn = a[i];
		sol += (mn * b[i]);
	}

	cout << sol << "\n";
}
