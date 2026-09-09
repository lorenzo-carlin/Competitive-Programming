#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ll n; cin >> n;
	while(n % 10) n = n * ((n%10)-1) / 2;
	cout << n << "\n";
}
