/*
 * Fenwick Tree
 * Supports efficient point updates and prefix-sum queries in O(log n) time.
 */


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct FenwickTree
{
	vector<int> bit;
	int n;

	FenwickTree(int _n)
	{
		 n = _n;
		 bit.assign(n, 0);
	}

	FenwickTree(vector<int> &a) : FenwickTree(a.size())
	{
		for(int i = 0; i < n; ++i)
		{
			bit[i] += a[i];
			int r = (i | (i+1));
			if(r < n) bit[r] += bit[i];
		}
	}

	int sum(int r)
	{
		int res = 0;
		while(r >= 0)
		{
			res += bit[r];
			r = (r & (r+1)) - 1;
		}
		return res;
	}

	int sum(int l, int r)
	{
		return sum(r) - sum(l-1);
	}

	void add(int ind, int delta)
	{
		while(ind < n)
		{
			bit[ind] += delta;
			ind = (ind | (ind+1));
		}
	}
};

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

