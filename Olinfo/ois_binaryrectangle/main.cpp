#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;

bool solve()
{
	int n, m; cin >> n >> m;
	char mat[n][m];
	pair<int,int> fst = {-1, -1}, lst = {-1, -1};
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cin >> mat[i][j];
			if(fst.first == -1 && mat[i][j] == '1')
			{
				fst = {i, j};
			}
			if(mat[i][j] == '1')
			{
				lst = {i, j};
			}
		}
	}
	if(fst.first == -1) return false;
	if(fst.second > lst.second) return false;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(fst.first <= i && lst.first >= i && fst.second <= j && lst.second >= j)
			{
				if(mat[i][j] == '0') return false;
			} else
			{
				if(mat[i][j] == '1') return false;
			}
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--)
	{
		if(solve()) cout << "1\n";
		else cout << "0\n";
	}
}
