#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> v(n);
	for(int &i: v) cin >> i;

	vector<int> s(n+1, INF);
	s[0] = -INF;

	for(int i = 0; i < n; ++i)
	{
		int l = lower_bound(begin(s), end(s), v[i]) - begin(s);
		s[l] = v[i];
	}

	int mx = 0;
	for(int i = 1; i <= n; ++i)
	{
		if(s[i] != INF)
		{
			mx = i;
		}
	}

	cout << mx << "\n";
}
