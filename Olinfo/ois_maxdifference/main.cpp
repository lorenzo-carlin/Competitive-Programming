#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<ll> v(n);
	for(auto &i: v) cin >> i;
	vector<ll> dp1(n+1, 0), dp2(n+1, 0);
	stack<int> mx, mn;
	ll ans = 0;
	for(int i = n-1; i >= 0; i--)
	{
		while(!mx.empty() && v[mx.top()] <= v[i])
		{
			mx.pop();
		}
		int up = (mx.empty()) ? (-1) : (mx.top());
		mx.push(i);
		while(!mn.empty() && v[mn.top()] >= v[i])
		{
			mn.pop();
		}
		int down = (mn.empty()) ? (-1) : (mn.top());
		mn.push(i);

		if(up != -1)
		{
			dp1[i] = max(dp1[up+1]+v[up]-v[i], dp2[up+1]+v[up]-v[i]);
			dp1[i] = max(dp1[i], dp1[up]+v[up]-v[i]);
			dp1[i] = max(dp1[i], dp2[up]);
		}
		if(down != -1)
		{
			dp2[i] = max(dp2[down+1]+v[i]-v[down], dp1[down+1]+v[i]-v[down]);
			dp2[i] = max(dp2[i], dp2[down]+v[i]-v[down]);
			dp2[i] = max(dp2[i], dp1[down]);
		}
		ans = max(ans, dp1[i]);
		ans = max(ans, dp2[i]);
	}

	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
