#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, k; cin >> n >> k;
	ll x, a, b, c; cin >> x >> a >> b >> c;
	ll sum = 0, ans = 0;

	deque<ll> d;
	d.push_back(x);
	sum += x;
	for(int i = 1; i < k; ++i)
	{
		d.push_back((d.back()*a + b) % c);
		sum += d.back();
	}
	ans = sum;

	for(int i = 0; i < n-k; ++i)
	{
		d.push_back((d.back()*a + b) % c);
		sum += d.back();
		sum -= d.front();
		d.pop_front();
		ans = ans ^ sum;
	}

	cout << ans << "\n";
}
