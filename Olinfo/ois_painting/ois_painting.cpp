#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

int n, k;
constexpr int dim = 17000;
int p[15];
bool g[10][10];
vector<bitset<dim>> sol(dim);

void solve(int h, int x, int y)
{
	if(h == 0)
	{
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				sol[x+i][y+j] = g[i][j];
			}
		}
	} else
	{
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if(g[i][j])
				{
					solve(h-1, x+i*p[h], y+j*p[h]);
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			char c; cin >> c;
			g[i][j] = (c == '.');
		}
		getchar_unlocked();
	}

	p[0] = 1;
	for(int i = 1; i <= k; ++i)
		p[i] = p[i-1]*n;

	solve(k-1, 0, 0);

	for(int i = 0; i < p[k]; ++i)
	{
		for(int j = 0; j < p[k]; ++j)
		{
			putchar_unlocked(sol[i][j] ? '.' : '*');
		}
		putchar_unlocked('\n');
	}
}
