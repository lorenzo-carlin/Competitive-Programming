#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n, x, y; cin >> n >> x >> y;
	vector<int> v(n+1);
	for(int i = y; i <= x; i++) v[i] = 1;
	bool cond = true;
	for(int i = x+1; i <= n; i++)
	{
		if(cond) v[i] = -1;
		else v[i] = 1;
		cond = !cond;
	}
	cond = true;
	for(int i = y-1; i >= 1; i--)
	{
		if(cond) v[i] = -1;
		else v[i] = 1;
		cond = !cond;
	}

	for(int i = 1; i <= n; ++i)
	{
		cout << v[i] << " ";
	}
	cout << "\n";
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
