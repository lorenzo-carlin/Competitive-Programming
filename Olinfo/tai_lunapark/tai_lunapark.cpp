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

	int find(int v)
	{
		if(par[v] == v) return v;
		else return par[v] = find(par[v]);
	}

	bool merge(int a, int b)
	{
		int A = find(a);
		int B = find(b);
		if(A == B) return false;
		else
		{
			par[A] = B;
			return true;
		}
	}
};

int progetta(int n, int m, int k, vector<int> &a, vector<int> &b, vector<int> &w)
{
	vector<vector<pair<int,int>>> counting_sort(1005);
	for(int i = 0; i < m; ++i) counting_sort[w[i]].push_back({a[i]-1, b[i]-1});

	DSU dsu = DSU(n);

	int sum = 0;
	stack<int> s;
	for(int i = 1000; i > 0; i--)
	{
		for(auto [x, y]: counting_sort[i])
		{
			if(dsu.merge(x, y))
			{
				sum += i;
				s.push(i);
			}
		}
	}

	for(int i = 0; i < k-1; ++i)
	{
		sum -= s.top();
		s.pop();
	}

	return sum;
}	
