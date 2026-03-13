#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	string s; cin >> s;
	int m; cin >> m;
	while(m--)
	{
		int a, b, c; cin >> a >> b >> c; a--; b--;
		c %= (b-a+1);
		string tmp;
		tmp += s.substr(b-c+1, c);
		tmp += s.substr(a, b-a+1-c);
		for(int i = 0; i < tmp.size(); ++i)
		{
			s[a+i] = tmp[i];
		}
	}

	cout << s << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
}
