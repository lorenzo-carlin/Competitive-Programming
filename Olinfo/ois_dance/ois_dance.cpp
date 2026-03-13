#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, d; cin >> n >> d;
	vector<int> v(n);
	for(auto &i: v) cin >> i;
	bool cond = true;
	for(int i = 0, a; i < n; i++)
	{
		cin >> a;
		if(a - v[i] > d)
		{
			cond = false;
		}
	}

	if(cond) cout << "YES\n";
	else cout << "NO\n";
}
