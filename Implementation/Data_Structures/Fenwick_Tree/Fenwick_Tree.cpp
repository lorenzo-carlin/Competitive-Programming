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
