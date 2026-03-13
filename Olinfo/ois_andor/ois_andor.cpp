#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for(auto &i: v) cin >> i;

	vector<int> last_bit(31, -1);
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < 30; ++j)
		{
			if(v[i] & (1 << j))
			{
				last_bit[j] = i;
			}
		}
	}

	for(auto el: last_bit) cout << el << " ";
	cout << "\n";

	int mn = 1e9;
	for(int j = 0; j < 30; ++j)
	{
		if(k & (1 << j))
		{
			/*
			if(last_bit[j] == -1)
			{
				cout << "NO\n";
				return;
			}
			*/
			mn = min(mn, last_bit[j]);
		}
	}
	cout << mn << "\n";
	
	int ans = 0;
	for(int i = mn; i < n; ++i)
	{
		ans = ans | v[i];
	}

	if(ans == k) cout << "YES\n";
	else cout << "NO\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
