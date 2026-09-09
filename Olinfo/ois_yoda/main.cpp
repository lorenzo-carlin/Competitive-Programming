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

	vector<string> v;
	string s;
	while(cin >> s)
	{
		v.push_back(s);
	}

	reverse(begin(v), end(v));
	for(auto el: v) cout << el << " ";
	}
