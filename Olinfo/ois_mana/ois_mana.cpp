#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k; cin >> n >> k;
	vector<int> v(n);
	for(auto &i: v) cin >> i;

	vector<int> order;
	int last = v[0];
	for(int i = 1; i < n; ++i)
	{
		if(v[i] < last)
		{
			order.push_back(v[i]);
		} else
		{
			order.push_back(last);
			last = v[i];
		}
	}

	vector<ll> ps(n, 0);
	for(int i = 0; i < n-1; i++)
	{
		ps[i+1] = ps[i] + order[i];
	}

	int rep = k/(n-1);
	int rem = k%(n-1);

	ll ans = rep*ps.back() + ps[rem];
	cout << ans << "\n";
}
