#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	int mat[n][m];
	vector<array<int,5>> moves;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cin >> mat[i][j];
		}
	}

	for(int i = n-1; i >= 0; i--)
	{
		for(int j = m-1; j > 2; j--)
		{
			moves.push_back({i, j-3, i, j-1,  mat[i][j]});
			moves.push_back({i, j-2, i, j  , -mat[i][j]});
			mat[i][j-3] += mat[i][j];
			mat[i][j] = 0;
		}
	}

	for(int i = n-1; i > 2; i--)
	{
		for(int j = 2; j >= 0; j--)
		{
			moves.push_back({i-3, j, i-1, j,  mat[i][j]});
			moves.push_back({i-2, j, i  , j, -mat[i][j]});
			mat[i-3][j] += mat[i][j];
			mat[i][j] = 0;
		}
	}

	// controllo se il 3X3 è valido
	for(int i = 0; i < 2; i++)
	{
		int dif_a = mat[i][0] - mat[i+1][0];
		int dif_b = mat[i][1] - mat[i+1][1];
		int dif_c = mat[i][2] - mat[i+1][2];
		if(dif_a != dif_b || dif_a != dif_c || dif_b != dif_c)
		{
			cout << "NO\n";
			return 0;
		}
	}

	int v;
	for(int i = 0; i < 3; i++)
	{
		v = min(mat[0][i], min(mat[1][i], mat[2][i]));
		mat[0][i] -= v;
		mat[1][i] -= v;
		mat[2][i] -= v;
		moves.push_back({0, i, 2, i, -v});
	}
	for(int i = 0; i < 3; i++)
	{
		v = mat[i][0];
		mat[i][0] -= v;
		mat[i][1] -= v;
		mat[i][2] -= v;
		moves.push_back({i, 0, i, 2, -v});
	}

	bool possible = true;
	for(int i = 0; i < 2; ++i)
	{
		for(int j = 0; j < 2; ++j)
		{
			if(mat[i][j] != 0)
			{
				possible = false;
			}
		}
	}

	if(!possible)
	{
		cout << "NO\n";
	} else
	{
		cout << "YES\n";
		cout << moves.size() << "\n";
		for(auto el: moves)
		{
			cout << el[0]+1 << " " << el[1]+1 << " " << el[2]+1 << " " << el[3]+1 << " " << el[4] << "\n";
		}
	}
}
