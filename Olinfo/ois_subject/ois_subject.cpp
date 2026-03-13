#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	vector<vector<int>> mat(m, vector<int> (m, 1));
	for(int i = 0, k; i < n; ++i)
	{
		cin >> k;
		vector<int> v(k);
		for(int i = 0; i < k; ++i)
		{
			cin >> v[i];
			v[i]--;
		}
		for(int i = 0; i < k; ++i)
		{
			for(int j = i+1; j < k; ++j)
			{
				mat[v[i]][v[j]] = 0;
				mat[v[j]][v[i]] = 0;
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < m; ++i)
	{
		for(int j = i+1; j < m; ++j)
		{
			ans += mat[i][j];
		}
	}
	cout << ans << "\n";
	for(int i = 0; i < m; ++i)
	{
		for(int j = i+1; j < m; ++j)
		{
			if(mat[i][j]) cout << i+1 << " " << j+1 << "\n";
		}
	}
}
