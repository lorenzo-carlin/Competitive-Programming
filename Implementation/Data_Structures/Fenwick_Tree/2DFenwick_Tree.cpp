#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct FenwickTree2D
{
	vector<vector<int>> bit;
	int n, m;

	FenwickTree2D(int _n, int _m)
	{
		n = _n;
		m = _m;
		bit.assign(n, vector<int>(m, 0));
	}

	FenwickTree2D(vector<vector<int>> &a) : FenwickTree2D(a.size(), a[0].size())
	{
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				add(i, j, a[i][j]);
			}
		}
	}

	void add(int x, int y, int delta)
	{
		for(int i = x; i < n; i = (i | (i+1)))
		{
			for(int j = y; j < m; j = (j | (j+1)))
			{
				bit[i][j] += delta;
			}
		}
	}

	int sum(int x, int y)
	{
		int res = 0;
		for(int i = x; i >= 0; i = (i & (i+1)))
		{
			for(int j = y; j >= 0; j = (j & (j+1)))
			{
				res += bit[i][j];
			}
		}
		return res;
	}
};
