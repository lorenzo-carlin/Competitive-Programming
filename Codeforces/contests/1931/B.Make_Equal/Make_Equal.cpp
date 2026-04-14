#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<int> v(n);
	int sum = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i];
		sum += v[i];
	}
	int target = sum / n, tmp = 0;
	for(int i = 0; i < n; ++i)
	{
		tmp += (v[i] - target);
		if(tmp < 0)
		{
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}

