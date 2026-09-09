#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 1005;
int t[MAXN][MAXN];
int tmr = 0;

void solve(int n)
{
	if(n == 1)
	{
		cout << tmr+0 << "\n";
	} else if(n == 2)
	{
		cout << tmr+0 << "\n";
	} else if(n == 3)
	{
		cout << tmr+1 << "\n";
		t[0][1] = t[1][1] = t[1][2] = t[2][2] = ++tmr;
	} else if(n == 4)
	{
		cout << tmr+4 << "\n";
		t[0][0] = t[0][1] = t[0][2] = t[1][1] = ++tmr;
		t[0][3] = t[1][2] = t[1][3] = t[2][3] = ++tmr;
		t[1][0] = t[2][0] = t[2][1] = t[3][0] = ++tmr;
		t[2][2] = t[3][1] = t[3][2] = t[3][3] = ++tmr;
	} else if(n == 5)
	{
		cout << tmr+6 << "\n";
		t[0][0] = t[1][0] = t[1][1] = t[2][0] = ++tmr;
		t[0][1] = t[0][2] = t[0][3] = t[1][2] = ++tmr;
		t[0][4] = t[1][3] = t[1][4] = t[2][3] = ++tmr;
		t[2][4] = t[3][3] = t[3][4] = t[4][4] = ++tmr;
		t[3][2] = t[4][1] = t[4][2] = t[4][3] = ++tmr;
		t[2][1] = t[3][0] = t[3][1] = t[4][0] = ++tmr;
	} else if(n == 6)
	{
		cout << tmr+8 << "\n";
		t[0][0] = t[0][1] = t[0][2] = t[1][1] = ++tmr;
		t[0][3] = t[0][4] = t[1][2] = t[1][3] = ++tmr;
		t[0][5] = t[1][4] = t[1][5] = t[2][5] = ++tmr;
		t[2][4] = t[3][4] = t[3][5] = t[4][5] = ++tmr;
		t[4][3] = t[4][4] = t[5][4] = t[5][5] = ++tmr;
		t[5][1] = t[4][2] = t[5][2] = t[5][3] = ++tmr;
		t[3][1] = t[4][0] = t[4][1] = t[5][0] = ++tmr;
		t[1][0] = t[2][0] = t[2][1] = t[3][0] = ++tmr;
	} else if(n == 7)
	{
		cout << tmr+12 << "\n";
		t[0][0] = t[0][1] = t[0][2] = t[1][1] = ++tmr;
		t[0][3] = t[0][4] = t[1][2] = t[1][3] = ++tmr;
		t[0][5] = t[0][6] = t[1][4] = t[1][5] = ++tmr;
		t[1][6] = t[2][5] = t[2][6] = t[3][6] = ++tmr;
		t[2][3] = t[2][4] = t[3][4] = t[3][5] = ++tmr;
		t[2][2] = t[3][2] = t[3][3] = t[4][2] = ++tmr;
		t[1][0] = t[2][0] = t[2][1] = t[3][1] = ++tmr;
		t[3][0] = t[4][0] = t[4][1] = t[5][0] = ++tmr;
		t[5][2] = t[5][3] = t[4][3] = t[4][4] = ++tmr;
		t[4][6] = t[5][5] = t[5][6] = t[6][6] = ++tmr;
		t[6][3] = t[6][4] = t[6][5] = t[5][4] = ++tmr;
		t[6][0] = t[6][1] = t[6][2] = t[5][1] = ++tmr;
	} else if(n == 10)
	{
		cout << tmr+25 << "\n";
		t[0][0] = t[0][1] = t[0][2] = t[1][1] = ++tmr;
		t[1][2] = t[1][3] = t[2][3] = t[2][4] = ++tmr;
		t[0][3] = t[0][4] = t[0][5] = t[1][4] = ++tmr;
		t[1][5] = t[1][6] = t[2][6] = t[2][7] = ++tmr;
		t[0][6] = t[0][7] = t[0][8] = t[1][7] = ++tmr;
		t[0][9] = t[1][9] = t[1][8] = t[2][8] = ++tmr;
		t[1][0] = t[2][0] = t[3][0] = t[2][1] = ++tmr;
		t[2][2] = t[3][2] = t[3][1] = t[4][1] = ++tmr;
		t[3][3] = t[4][3] = t[5][3] = t[4][2] = ++tmr;
		t[4][4] = t[3][4] = t[3][5] = t[2][5] = ++tmr;
		t[3][6] = t[3][7] = t[4][7] = t[4][8] = ++tmr;
		t[2][9] = t[3][9] = t[4][9] = t[3][8] = ++tmr;
		t[5][4] = t[5][5] = t[4][5] = t[4][6] = ++tmr;
		t[4][0] = t[5][0] = t[6][0] = t[5][1] = ++tmr;
		t[7][0] = t[8][0] = t[9][0] = t[8][1] = ++tmr;
		t[5][2] = t[6][2] = t[6][1] = t[7][1] = ++tmr;
		t[7][2] = t[7][3] = t[7][4] = t[6][3] = ++tmr;
		t[6][4] = t[6][5] = t[6][6] = t[7][5] = ++tmr;
		t[5][6] = t[5][7] = t[5][8] = t[6][7] = ++tmr;
		t[5][9] = t[6][9] = t[6][8] = t[7][8] = ++tmr;
		t[7][9] = t[8][9] = t[9][9] = t[8][8] = ++tmr;
		t[8][5] = t[8][6] = t[7][6] = t[7][7] = ++tmr;
		t[9][1] = t[9][2] = t[8][2] = t[8][3] = ++tmr;
		t[9][3] = t[9][4] = t[9][5] = t[8][4] = ++tmr;
		t[9][6] = t[9][7] = t[9][8] = t[8][7] = ++tmr;
	} else if(n % 2 == 0)
	{
		// quadrato in basso a destra
		t[n-4][n-4] = t[n-4][n-3] = t[n-4][n-2] = t[n-3][n-3] = ++tmr;
		t[n-4][n-1] = t[n-3][n-2] = t[n-3][n-1] = t[n-2][n-1] = ++tmr;
		t[n-2][n-2] = t[n-1][n-3] = t[n-1][n-2] = t[n-1][n-1] = ++tmr;
		t[n-1][n-4] = t[n-2][n-4] = t[n-2][n-3] = t[n-3][n-4] = ++tmr;

		// rettangolo in alto a destra
		t[0][n-4] = t[0][n-3] = t[0][n-2] = t[1][n-3] = ++tmr;
		t[0][n-1] = t[1][n-1] = t[2][n-1] = t[1][n-2] = ++tmr;
		t[n-7][n-4] = t[n-6][n-4] = t[n-6][n-3] = t[n-5][n-4] = ++tmr;
		t[n-6][n-2] = t[n-5][n-3] = t[n-5][n-2] = t[n-5][n-1] = ++tmr;
		for(int i = 0; i < n-4; i++)
		{
			for(int j = n-4; j < n; j++)
			{
				if(t[i][j] == 0)
				{
					t[i][j] = t[i+1][j] = t[i+1][j+1] = t[i+2][j+1] = ++tmr;
				}
			}
		}

		// rettangolo in basso a sinistra
		t[n-1][0] = t[n-2][0] = t[n-2][1] = t[n-3][0] = ++tmr;
		t[n-4][0] = t[n-4][1] = t[n-4][2] = t[n-3][1] = ++tmr;
		t[n-1][n-7] = t[n-1][n-6] = t[n-1][n-5] = t[n-2][n-6] = ++tmr;
		t[n-2][n-5] = t[n-3][n-5] = t[n-4][n-5] = t[n-3][n-6] = ++tmr;
		for(int j = 0; j < n-4; j++)
		{
			for(int	i = n-4; i < n; i++)
			{
				if(t[i][j] == 0)
				{
					t[i][j] = t[i][j+1] = t[i-1][j+1] = t[i-1][j+2] = ++tmr;
				}
			}
		}

		solve(n-4);
	} else if(n % 2 == 1)
	{
		// quadrato in basso a destra
		t[n-4][n-4] = t[n-4][n-3] = t[n-4][n-2] = t[n-3][n-3] = ++tmr;
		t[n-4][n-1] = t[n-3][n-2] = t[n-3][n-1] = t[n-2][n-1] = ++tmr;
		t[n-2][n-2] = t[n-1][n-3] = t[n-1][n-2] = t[n-1][n-1] = ++tmr;
		t[n-1][n-4] = t[n-2][n-4] = t[n-2][n-3] = t[n-3][n-4] = ++tmr;

		// rettangolo in alto a destra
		t[0][n-4] = t[0][n-3] = t[0][n-2] = t[1][n-3] = ++tmr;
		t[1][n-4] = t[2][n-4] = t[3][n-4] = t[2][n-3] = ++tmr;
		t[n-5][n-4] = t[n-5][n-3] = t[n-5][n-2] = t[n-6][n-3] = ++tmr;
		t[n-5][n-1] = t[n-6][n-1] = t[n-6][n-2] = t[n-7][n-1] = ++tmr;
		for(int i = 0; i < n-4; i++)
		{
			for(int j = n-4; j < n; j++)
			{
				if(t[i][j] == 0)
				{
					t[i][j] = t[i+1][j] = t[i+1][j-1] = t[i+2][j-1] = ++tmr;
				}
			}
		}

		// rettangolo in basso a sinistra
		t[n-1][0] = t[n-2][0] = t[n-2][1] = t[n-3][0] = ++tmr;
		t[n-1][1] = t[n-1][2] = t[n-2][2] = t[n-1][3] = ++tmr;
		t[n-1][n-5] = t[n-2][n-5] = t[n-2][n-6] = t[n-3][n-5] = ++tmr;
		t[n-4][n-7] = t[n-4][n-6] = t[n-4][n-5] = t[n-3][n-6] = ++tmr;
		for(int j = 0; j < n-4; j++)
		{
			for(int i = n-4; i < n; i++)
			{
				if(t[i][j] == 0)
				{
					t[i][j] = t[i][j+1] = t[i+1][j+1] = t[i+1][j+2] = ++tmr;
				}
			}
		}

		solve(n-4);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i = 0; i < MAXN; ++i)
	{
		for(int j = 0; j < MAXN; ++j)
		{
			t[i][j] = 0;
		}
	}

	int n; cin >> n;
	solve(n);

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cout << t[i][j] << " ";
		}
		cout << "\n";
	}
}
