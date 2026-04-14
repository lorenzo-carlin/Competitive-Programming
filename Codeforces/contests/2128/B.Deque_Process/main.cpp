#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<int> v(n);
	for(auto &i: v) cin >> i;

	int l = 0, r = n-1;
	bool status = true;

	while(l < r)
	{
		char mn = (v[l] < v[r]) ? ('L') : ('R');
		char mx = (v[l] > v[r]) ? ('L') : ('R');
		if(status)
		{
			cout << mn << mx;
		} else
		{
			cout << mx << mn;
		}
		status = !status;
		l++; r--;
	}

	if(l == r) cout << 'L';
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
