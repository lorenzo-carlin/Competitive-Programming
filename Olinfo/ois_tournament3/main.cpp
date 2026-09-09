#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	int mx1, mx2, m1 = 0, m2 = 0;
	for(int i = 0, p; i < n/2; ++i)
	{
		cin >> p;
		if(p > m1)
		{
			m1 = p;
			mx1 = i;
		}
	}
	for(int i = n/2, p; i < n; ++i)
	{
		cin >> p;
		if(p > m2)
		{
			m2 = p;
			mx2 = i;
		}
	}
	if(m1 > m2) cout << mx1 << " " << mx2 << "\n";
	else cout << mx2 << " " << mx1 << "\n";
}
