#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	ll l, r; cin >> l >> r;
	ll tot = r-l+1;

	auto count_divisors = [&] (ll v) -> ll
	{
		ll up = (r/v);
		ll down = ((l-1)/v);
		return up-down;
	};

	tot += count_divisors(210);
	tot -= count_divisors(105);
	tot -= count_divisors(70);
	tot -= count_divisors(42);
	tot -= count_divisors(30);
	tot += count_divisors(35);
	tot += count_divisors(21);
	tot += count_divisors(15);
	tot += count_divisors(14);
	tot += count_divisors(10);
	tot += count_divisors(6);
	tot -= count_divisors(7);
	tot -= count_divisors(5);
	tot -= count_divisors(3);
	tot -= count_divisors(2);

	cout << tot << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
