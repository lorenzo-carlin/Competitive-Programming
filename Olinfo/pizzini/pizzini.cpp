#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; cin >> n;
	vector<string> str(n);
	map<vector<int>,int> mp;
	vector<vector<int>> v(n);
	for(int i = 0; i < n; i++)
	{
		cin >> str[i];
		vector<int> occ(10, 0);
		for(char c: str[i])
		{
			int car = c - '0';
			occ[car]++;
		}
		v[i] = occ;
		mp[occ]++;
	}

	string ans;
	for(int i = 0; i < n; i++)
	{
		ans += str[i][mp[v[i]]-1];
	}

	cout << ans << "\n";
}
