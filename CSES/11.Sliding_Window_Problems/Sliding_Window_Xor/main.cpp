#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, k; cin >> n >> k;
	ll x, a, b, c; cin >> x >> a >> b >> c;
	ll cur = x, ans = 0;

	deque<int> d;
	d.push_back(x);
	for(int i = 1; i < k; ++i)
	{
		d.push_back((d.back()*a + b) % c);
		cur = cur ^ d.back();
	}
	ans = cur;

	for(int i = 0; i < n-k; ++i)
	{
		d.push_back((d.back()*a + b) % c);
		cur = cur ^ d.back();
		cur = cur ^ d.front();
		d.pop_front();
		ans = ans ^ cur;
	}

	cout << ans << "\n";
}
