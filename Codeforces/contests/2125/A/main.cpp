#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	string s; cin >> s;
	int cnt = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == 'T') cnt++;
	}
	for(int i = 0; i < cnt; ++i)
	{
		cout << 'T';
	}
	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i] == 'T') continue;
		cout << s[i];
	}
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
