#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU
{
	int n;
	vector<int> par;

	DSU() {}
	DSU(int _n)
	{
		n = _n;
		par.resize(n);
		iota(begin(par), end(par), 0);
	}

	int find(int a)
	{
		if(par[a] == a) return a;
		else return par[a] = find(par[a]);
	}

	bool merge(int a, int b)
	{
		int A = find(a);
		int B = find(b);

		if(A == B) return false;
		par[A] = B;
		return true;
	}
};

DSU dsu;
int ans;

void inizia(int n)
{
	dsu = DSU(n);
	ans = n;
}

int collega(int x, int y)
{
	if(dsu.merge(x, y)) ans--;
	return ans;
}
