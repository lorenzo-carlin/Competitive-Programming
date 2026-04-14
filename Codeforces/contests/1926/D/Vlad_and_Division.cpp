#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll target = 2147483647;

void solve()
{
	int n; cin >> n;
	vector<ll> v(n);
	for(auto &i: v) cin >> i;

	sort(rbegin(v), rend(v));

	int ans = n;
	int l = 0, r = n-1;
	for(; l < r; l++)
	{
		while(v[l] + v[r] < target && l < r)
		{
			r--;
		}
		if(v[l] + v[r] == target)
		{
			ans--;
			r--;
		}
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

