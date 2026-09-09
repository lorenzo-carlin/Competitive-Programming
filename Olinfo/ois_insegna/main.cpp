#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; cin >> n;
	string a, b; cin >> a >> b;
	for(int i = 0; i < n; ++i)
	{
		string tmp = b.substr(i, n-i) + b.substr(0, i);
		if(tmp == a)
		{
			cout << "1\n";
			return 0;
		}
	}

	cout << "0\n";
}
