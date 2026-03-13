#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<ll> v(n);
	for(auto &i: v) cin >> i;

	vector<ll> cost(n, 0);
	vector<ll> ps(n);
	for(int i = 1; i < n; ++i)
	{
		if(v[i] == 1 && v[i-1] > 1)
		{
			cout << -1 << "\n";
			return;
		}

		if(v[i] < v[i-1])
		{
			ll tmp = v[i];
			ll cnt = 0;
			while(tmp < v[i-1])
			{
				tmp = tmp*tmp;
				cnt++;
			}
			cost[i] = cnt;
		} else
		{
			ll tmp = v[i];
			ll cnt = 0;
			while(tmp > v[i-1])
			{
				tmp = sqrt(tmp);
				cnt++;
			}
			if(tmp < v[i-1]) cnt--;
			cost[i] = -cnt;
		}
	}

	ll sol = 0;
	ps[0] = 0;
	for(int i = 1; i < n; ++i)
	{
		ps[i] = max((ll)0, ps[i-1]+cost[i]);		
	}
	for(int i = 0; i < n; ++i)
	{
		sol += ps[i];
	}

	cout << sol << "\n";
}	


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
