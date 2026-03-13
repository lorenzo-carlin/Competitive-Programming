#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	bool mat[n][m];
	char c;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cin >> c;
			if(c == '.') mat[i][j] = false;
			else mat[i][j] = true;
		}
	}

	int ans = 0;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(!mat[i][j]) continue;

			if(!mat[i-1][j]) ans++;
			if(!mat[i][j-1]) ans++;
			if(!mat[i+1][j]) ans++;
			if(!mat[i][j+1]) ans++;
		}
	}

	cout << ans << "\n";
}
