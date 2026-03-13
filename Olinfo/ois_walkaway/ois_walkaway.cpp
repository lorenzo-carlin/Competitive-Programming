#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(auto &i: v) cin >> i;
	sort(v.begin(), v.end());

	int sol = INT_MAX;
	for(int l = 0, r = k-1; r < n; l++, r++)
	{
		sol = min(sol, v[r]-v[l]);
	}

	cout << sol << "\n";
}
