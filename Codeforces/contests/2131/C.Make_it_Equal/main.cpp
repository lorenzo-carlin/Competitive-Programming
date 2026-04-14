#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n, k; cin >> n >> k;
	map<int,int> cnt1, cnt2;
	for(int i = 0, a; i < n; ++i)
	{
		cin >> a;
		int r = a % k;
		cnt1[r]++;
		cnt1[k-r]++;
	}
	for(int i = 0, a; i < n; ++i)
	{
		cin >> a;
		int r = a % k;
		cnt2[r]++;
		cnt2[k-r]++;
	}

	bool possible = true;
	for(auto el: cnt2)
	{
		if(cnt1[el.first] != el.second)
		{
			possible = false;
		}
	}

	if(possible) cout << "Yes\n";
	else cout << "No\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
