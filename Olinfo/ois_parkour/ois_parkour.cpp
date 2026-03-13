#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r, c; cin >> r >> c;

	if(r > c)
	{
		cout << "-1\n";
		return 0;
	}

	vector<vector<char>> mat(r, vector<char> (c, '.'));
	for(int i = 1; i < r; ++i)
	{
		for(int j = 0; j < i; ++j)
		{
			mat[i][j] = '#';
		}
	}

	for(int i = 0; i < r; ++i)
	{
		for(int j = 0; j < c; ++j)
		{
			cout << mat[i][j];
		}
		cout << "\n";
	}
}
