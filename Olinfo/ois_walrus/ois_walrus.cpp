#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<int> inter;
	int cnt = 0;
	for(int i = 0; i < n; ++i)
	{
		char c; cin >> c;
		if(c == '.') cnt++;
		else if(cnt != 0)
		{
			inter.push_back(cnt);
			cnt = 0;
		}
	}
	if(cnt != 0) inter.push_back(cnt);

	sort(rbegin(inter), rend(inter));
	int fn = 0;
	for(int i = 0; i < inter.size(); ++i)
	{
		int p = inter[i]/2+1;
		fn = max(fn, i+p);
	}

	cout << inter.size() << " " << fn << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
