#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, k; cin >> n >> k;
	ll x, a, b, c; cin >> x >> a >> b >> c;
	ll ans = 0;

	deque<ll> d;
	priority_queue<pair<int,int>> pq;
	d.push_back(x);
	pq.push({-x,0});
	for(int i = 1; i < k; ++i)
	{
		d.push_back((d.back()*a + b) % c);
		pq.push({-d.back(), i});
	}
	ans = -pq.top().first;

	for(int i = 0; i < n-k; ++i)
	{
		d.push_back((d.back()*a + b) % c);
		pq.push({-d.back(), i+k});
		d.pop_front();
		while(pq.top().second <= i) pq.pop();
		ans = ans ^ (-pq.top().first);
	}

	cout << ans << "\n";
}
