#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void add(vector<int> s, ll x);

bool compare(int i, int j);

void make_all_equal(int n, int Q_add, int Q_compare)
{
	vector<int> add_index;
	for(int p = 2; p <= n; p *= 2)
	{
		add_index.clear();
		for(int i = 0; i < n; i += p)
		{
			for(int j = 0; j < p/2; ++j)
			{
				add_index.push_back(i+j);
			}
		}
		for(int j = 18 + log2(p); j >= 0; j--) add(add_index, (1 << j));

		add_index.clear();
		for(int i = 0; i < n; i += p)
		{
			if(!compare(i, i+(p/2)))
			{
				for(int j = i; j < i+(p/2); j++) add_index.push_back(j);
			}
		}
		if(!add_index.empty()) add(add_index, 1);
	}
	return;
}		
