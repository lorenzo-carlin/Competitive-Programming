#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int binary_search(vector<int> &v, int val)
{
	int l = 0, r = v.size()-1;
	while(l < r)
	{
		int m = (l+r)/2;
		if(v[m] < val)
		{
			l = m+1;
		} else
		{
			r = m;
		}
	}

	if(v[r] < val) return r+1;
	else return r;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);

	int n, q; cin >> n >> q;
	vector<int> v(n);
	for(int &i: v) cin >> i;

	sort(begin(v), end(v));

	while(q--)
	{
		int a, b; cin >> a >> b;
		int l = binary_search(v, a);
		int r = binary_search(v, b+1);
		cout << r-l << "\n";
	}
}
