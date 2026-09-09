#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k; cin >> n >> k;
	vector<int> v(n);
	for(auto &i: v) cin >> i;
	sort(begin(v), end(v));

	int mx = 0, mx_ind = -1;

	for(int i = 0; i < n-1; ++i)
	{
		if((v[i+1]-v[i])/2 > mx)
		{
			mx = (v[i+1]-v[i])/2;
			mx_ind = v[i]+mx;
		}
	}
	if(v[0] > mx)
	{
		mx = v[0];
		mx_ind = 0;
	}
	if((k-v[n-1]) > mx)
	{
		mx = (k-v[n-1]);
		mx_ind = k;
	}

	cout << mx_ind << "\n";
}
