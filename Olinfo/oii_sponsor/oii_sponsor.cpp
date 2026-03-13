#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

constexpr int MAXN = 1e4+5;

int solve(int n, int m, int *q, int **sponsors, int *a, int *b)
{
	vector<bitset<MAXN>> listasponsor(m);
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < q[i]; ++j)
		{
			listasponsor[sponsors[i][j]-1][i] = 1;
		}
	}

	for(int i = 0, cnt, dim1, dim2; i < m; ++i)
	{
		for(int j = 0; j < i; ++j)
		{
			cnt = (listasponsor[i] | listasponsor[j]).count();
			dim1 = listasponsor[i].count();
			dim2 = listasponsor[j].count();
			if(!((cnt == dim1+dim2) || (cnt == dim1 || cnt == dim2)))
			{
				a[0] = i+1;
				b[0] = j+1;
				return 0;
			}			
		}
	}

	return 1;
}
