#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	char mat[3][3];
	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			cin >> mat[i][j];
		}
	}

	int M[3][3];
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
			M[i][j] = '.';

	int pro = 0, con = 0;

	auto check = [&] () -> bool
	{
		int a = 0, b = 0;
		for(int i = 0; i < 3; ++i)
		{
			for(int j = 0; j < 3; ++j)
			{
				if(M[i][j] == 'X') a++;
				else b++;

				if(mat[i][j] == 'X' && M[i][j] == 'O')
					return false;
				if(mat[i][j] == 'O' && M[i][j] == 'X')
					return false;
			}
		}
		if(a == 5 && b == 4)
			return true;
		else
			return false;
	};

	auto find = [&] () -> bool
	{
		if((M[0][0] == M[0][1] == M[0][2] == 'X') || (M[1][0] == M[1][1] == M[1][2] == 'X') || (M[2][0] == M[2][1] == M[2][2] == 'X') || (M[0][0] == M[1][0] == M[2][0] == 'X') || (M[0][1] == M[1][1] == M[2][1] == 'X') || (M[0][2] == M[1][2] == M[2][2] == 'X') || (M[0][0] == M[1][1] == M[2][2] == 'X') || (M[0][2] == M[1][1] == M[2][0] == 'X'))
			return true;
		else
			return false;
	};

	auto generate = [&] (auto generate, int x, int y) -> void
	{
		if(y == 3)
		{
			if(check())
			{
				if(find())
					pro++;
				else
					con++;
			}
			return;
		}

		M[x][y] = 'X';
		if(x == 2)
			generate(generate, 0, y+1);
		else
			generate(generate, x+1, y);
		M[x][y] = 'O';
		if(x == 2)
			generate(generate, 0, y+1);
		else
			generate(generate, x+1, y);
	};

	generate(generate, 0, 0);

	if(pro > 0 && con == 0)
		cout << 1 << "\n";
	else
		cout << 0 << "\n";

}
