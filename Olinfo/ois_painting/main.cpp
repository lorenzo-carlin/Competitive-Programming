#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k; cin >> n >> k;
	vector<int> pot(k+1, 1);
	for(int i = 1; i <= k; i++)
		pot[i] = pot[i-1]*n;
	int dim = pot[k];

	vector<vector<char>> st(n, vector<char> (dim));
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cin >> st[i][j];
		}
		getchar_unlocked();
	}

	for(int i = 0; i < dim; ++i)
	{
		for(int j = 0; j < dim; ++j)
		{
			bool cond = false;
			int a = i, b = j;
			for(int step = 1; step <= k; step++)
			{
				//int x = (i % pot[k-step+1])/(pot[k-step]);
				int x = a % n;
				//int y = (j % pot[k-step+1])/(pot[k-step]);
				int y = b % n;
				if(st[x][y] == '*')
				{
					putchar_unlocked('*');
					cond = true;
					break;
				}
				a /= n;
				b /= n;
			}
			if(!cond) putchar_unlocked('.');
		}
		putchar_unlocked('\n');
	}
}
