#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	string s; cin >> s;
	s.pop_back();
	s.pop_back();
	s.push_back('i');
	cout << s << "\n";
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
