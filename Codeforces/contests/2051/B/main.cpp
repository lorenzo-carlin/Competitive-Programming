#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n, a, b, c; cin >> n >> a >> b >> c;
	int tot = a+b+c;
	int day = 3*(n/tot);
	int rem = n%tot;
	if(rem == 0)
	{
		cout << day << "\n";
	} else if(rem <= a)
	{
		cout << day+1 << "\n";
	} else
	{
		rem -= a;
		if(rem <= b)
		{
			cout << day+2 << "\n";
		} else
		{
			cout << day+3 << "\n";
		}
	}
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
