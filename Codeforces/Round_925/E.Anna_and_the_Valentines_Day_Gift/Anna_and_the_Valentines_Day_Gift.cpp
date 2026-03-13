#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n, m; cin >> n >> m;
	vector<pair<int,int>> v(n);
	for(int i, a; i < n; ++i)
	{
		cin >> a;
		int cnt = 0;
		while(a % 10 == 0)
		{
			a  = a/10;
			cnt++;
		}
		v[i].first = cnt;
		cnt = 0;
		while(a > 0)
		{
			a  = a/10;
			cnt++;
		}
		v[i].second = cnt;
	}
	sort(rbegin(v), rend(v));
	bool cond = false;
	int cnt = 0;
	for(int i = 0; i < n; ++i)
	{
		cnt += v[i].second;
		if(cond) cnt += v[i].first;
		cond = !cond;
	}
	if(cnt > m) cout << "Sasha\n";
	else cout << "Anna\n";
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}

