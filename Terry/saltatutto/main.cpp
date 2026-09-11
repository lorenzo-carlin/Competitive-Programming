#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t; cin >> t;
	for(int x = 1; x <= t; x++)
	{
		int n; cin >> n;
		vector<int> v(n);
		for(auto &i: v) cin >> i;

		string ans;
		int i;
		for(i = 1; i < n; ++i)
		{
			if(v[i])
			{
				ans += 'S';
				i++;
			} else
			{
				ans += 'A';
			}
		}
		if(i == n) ans += 'A';

		cout << "Case #" << x << ": " << ans << endl;
	}
}
