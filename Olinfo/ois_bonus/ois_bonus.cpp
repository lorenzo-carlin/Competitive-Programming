#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<pair<ll,ll>> v(n);
	ll num = 0, den = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i].first >> v[i].second;
		num += v[i].first;
		den += v[i].second;
	}

	ll A = 0, B = 0;
	int mx_ind = -1;
	for(int i = 0; i < n; ++i)
	{
		ll a = v[i].first;
		ll b = v[i].second;
		if((num-a)*(den-B) >= (num-A)*(den-b))
		{
			mx_ind = i;
			A = a;
			B = b;
		}
	}

	cout << mx_ind << "\n";
}
