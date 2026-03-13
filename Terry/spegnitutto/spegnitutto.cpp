#include <bits/stdc++.h>
using namespace std;

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

		int ans = 0;
		
		for(int i = 0; i < n-1; ++i)
		{
			if(v[i] && v[i+1])
			{
				v[i] = 0;
				v[i+1] = 0;
				ans++;
			}
		}

		for(int i = 0; i < n; ++i)
		{
			ans += v[i];
		}

		cout << "Case #" << x << ": " << ans << "\n";
	}
}
