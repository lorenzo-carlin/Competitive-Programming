#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> v(n);
	for(auto &i: v) cin >> i;

	int ans = 0, l, r, val;
	for(int i = 0; i < 2*n-1; i++)
	{
		l = i/2;
		r = (i+1)/2;
		if(min(n-r, l-0+1)*2 <= ans) break;
		val = -1;
		while(l >= 0 && r < n)
		{
			if(v[l] != v[r] && v[l] != -1 && v[r] != -1) break;
			if(min(v[l], v[r]) == -1 && max(v[l], v[r]) != -1 && val == -1) val = max(v[l], v[r]);
			if(v[l] == -1 && v[r] != val && v[r] != -1) break;
			if(v[r] == -1 && v[l] != val && v[l] != -1) break;

			ans = max(ans, r-l+1);
			l--; r++;
		}
	}
	cout << ans << "\n";
}
