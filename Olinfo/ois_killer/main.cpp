#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--)
	{
		ll n, k; cin >> n >> k;
		ll first = k*(k+1)/2;
		if(k == 1 || n-first == 0 || n-first == 1) cout << "YES\n";
		else cout << "NO\n";
	}
}
