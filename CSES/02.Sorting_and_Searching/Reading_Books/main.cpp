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

	sort(rbegin(v), rend(v));
	ll max = v[0], rem = 0;
	for(int i = 1; i < n; ++i)
	{
		rem += v[i];
	}

	if(max >= rem)
	{
		cout << 2*max << "\n";
	} else
	{
		cout << max+rem << "\n";
	}
}
