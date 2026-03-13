#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string decrypt(string s, int key)
{
	string a = s;
	for(int i = 0; i < a.size(); ++i)
	{
		int c = a[i] - 'a';
		c += (26 - key);
		c %= 26;
		a[i] = 'a' + c;
	}
	return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	map<string,int> mp;
	while(n--)
	{
		string s; cin >> s;
		s = decrypt(s, s[0]-'a');
		mp[s]++;
	}

	int mx = 0;
	for(auto el: mp) mx = max(mx, el.second);
	cout << mx << "\n";
}
