#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n, m, k; cin >> n >> m >> k;
	vector<int> v(m);
	for(int &i: v) cin >> i;
	set<int> q;
	for(int i = 0; i < k; ++i)
	{
		int p; cin >> p;
		q.insert(p);
	}

	for(int i = 0; i < m; ++i)
	{
		if((n-k) > 1) cout << "0";
		else if(n == k) cout << "1";
		else
		{
			if(!q.count(v[i])) cout << "1";
			else cout << "0";
		}
	}
	cout << "\n";
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
