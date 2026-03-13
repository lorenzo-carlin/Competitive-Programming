#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	string s; cin >> s;
	char c = s[0];
	for(int i = 1; i < s.size(); ++i)
	{
		c = min(c, s[i]);
	}

	cout << c << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
