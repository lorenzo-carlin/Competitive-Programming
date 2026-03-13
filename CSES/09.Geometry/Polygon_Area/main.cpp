#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<ll> x(n), y(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> x[i] >> y[i];
	}

	ll area = 0;
	for(int i = 0; i < n-1; ++i)
	{
		area += (x[i]*y[i+1]);
		area -= (x[i+1]*y[i]);
	}
	area += (x.back()*y.front());
	area -= (x.front()*y.back());

	cout << abs(area) << "\n";
}
