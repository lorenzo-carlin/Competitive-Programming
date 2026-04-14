#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<int> ans(2*n);
	set<int> s;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			int num; cin >> num;
			ans[i+j-1] = num;
			s.insert(num);
		}
	}
	for(int i = 1; i <= 2*n; ++i)
	{
		if(!s.count(i))
		{
			ans[0] = i;
		}
	}
	for(auto el: ans) cout << el << " ";
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
