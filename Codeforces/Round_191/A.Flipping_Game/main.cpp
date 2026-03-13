#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> v(n);
	for(auto &i: v) cin >> i;
	int on = 0;
	for(auto i: v) if(i) on++;

	int mx = 0;

	for(int i = 0; i < n; ++i)
	{
		int uno = 0, zero = 0;
		for(int j = i; j < n; ++j)
		{
			if(v[j]) uno++;
			else zero++;

			mx = max(mx, on+zero-uno);
		}
	}

	cout << mx << "\n";
}
