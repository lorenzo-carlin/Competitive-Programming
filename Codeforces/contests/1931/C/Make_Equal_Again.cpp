#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<int> v(n);
	for(int &i: v) cin >> i;

	int l = 1;
	for(int i = 0; i < n-1; ++i)
	{
		if(v[i] == v[i+1]) l++;
		else break;
	}

	int r = 1;
	for(int i = n-1; i > 0; i--)
	{
		if(v[i] == v[i-1]) r++;
		else break;
	}

	if(v.front() == v.back()) cout << max(0, n - l - r) << "\n";
	else cout << n - max(l, r) << "\n";
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}

