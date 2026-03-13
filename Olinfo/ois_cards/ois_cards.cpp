#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, r, c; cin >> n >> r >> c;

	ll rem_sotto = n*(n+1)/2 - r*(r+1)/2;
	ll rem_dx = (r-c)*(r-c+1)/2;
	ll rem_sx = (c-1)*c/2;

	ll tot = n*(n+1)/2 - (rem_sotto + rem_dx + rem_sx);
	cout << tot << "\n";
}
