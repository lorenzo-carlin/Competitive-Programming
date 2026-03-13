#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k; cin >> n >> k;
	vector<int> v(n);
	for(int &i: v) cin >> i;

	int mx = -1e9;
	int tmp = 0;
	for(int i = 0; i < k; ++i) tmp += v[i];
	mx = max(mx, tmp);

	int l = 0, r = k;
	while(r < n)
	{
		tmp -= v[l];
		l++;
		tmp += v[r];
		r++;
		mx = max(mx, tmp);
	}
	cout << mx << "\n";
}
