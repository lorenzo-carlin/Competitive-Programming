#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, v; cin >> n >> v;
	vector<int> a(n), b(v);
	for(int &i: a) cin >> i;
	for(int &i: b) cin >> i;

	int l = 0, r = 0;
	int sol = 0;
	sort(begin(a), end(a));
	sort(begin(b), end(b));

	while(l < n && r < v)
	{
		if(b[r] >= a[l])
		{
			l++;
			r++;
			sol++;
		} else
		{
			r++;
		}
	}

	cout << sol << "\n";
}
