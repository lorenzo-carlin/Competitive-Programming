#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, l, k; cin >> n >> m >> l >> k;

	if(k == 0)
	{
		cout << "YES\n";
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				cout << 'R';
			}
			cout << "\n";
		}
		return 0;
	}

	if((m-l+1)*(n-l+1) < k || l % 3 != 0)
	{
		cout << "NO\n";
		return 0;
	}

	char mat[n][m];

	int r = k / (m-l+1); // volte in cui il quadrato si ripete in verticale
	int r_da_col = r+l-1;
	for(int i = 0; i < r_da_col; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(i % 3 == 0) mat[i][j] = 'R';
			if(i % 3 == 1) mat[i][j] = 'B';
			if(i % 3 == 2) mat[i][j] = 'G';
		}
	}

	int c = k % (m-l+1); // volte in cui il quadrato si ripete in orizzontale
	int c_da_col = (c == 0) ? (0) : (c+l-1);
	for(int j = 0; j < c_da_col; ++j)
	{
		if(r_da_col % 3 == 0) mat[r_da_col][j] = 'R';
		if(r_da_col % 3 == 1) mat[r_da_col][j] = 'B';
		if(r_da_col % 3 == 2) mat[r_da_col][j] = 'G';
	}

	char col;
	if(r_da_col % 3 == 0) col = 'G';
	if(r_da_col % 3 == 1) col = 'R';
	if(r_da_col % 3 == 2) col = 'B';

	for(int j = c_da_col; j < m; ++j)
	{
		mat[r_da_col][j] = col;
	}

	for(int i = r_da_col+1; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			mat[i][j] = col;
		}
	}

	cout << "YES\n";
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cout << mat[i][j];
		}	
		cout << "\n";
	}
}
