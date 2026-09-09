#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	ll m; cin >> m;

	vector<ll> v(n), ps(n+1); ps[0] = 0;
	for(auto &i: v)
	{
		cin >> i;
	}
	for(int i = 1; i <= n; ++i)
	{
		ps[i] = ps[i-1] + v[i-1];
	}

	ll sum = ps.back();
	ll rem = m % sum;
	if(rem == 0)
	{
		cout << n-1 << "\n";
	} else
	{
		int sol = lower_bound(begin(ps), end(ps), rem) - begin(ps) - 1;
		cout << sol << "\n";
	}
}
