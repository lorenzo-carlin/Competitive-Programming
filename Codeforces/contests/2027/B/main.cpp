#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<int> v(n), a(n);
	for(int &i: v) cin >> i;

	multiset<int> ms;
	for(int i = n-1; i >= 0; i--)
	{
		auto it1 = ms.upper_bound(v[i]);
		a[i] = distance(it1, ms.end());

		ms.insert(v[i]);
	}

	int mn = 1e9;
	for(int i = 0; i < n; ++i)
	{
		mn = min(mn, i+a[i]);
	}

	cout << mn << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	while(n--) solve();
}
