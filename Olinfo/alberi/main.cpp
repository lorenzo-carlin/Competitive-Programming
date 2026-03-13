#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void visita(int n, int *pre, int *post, int *simm)
{
	vector<int> pr(n), po(n), si(n);
	for(int i = 0; i < n; ++i)
	{
		pr[i] = pre[i]-1;
		po[i] = post[i]-1;
	}

	vector<int> pos_in_post(n);
	for(int i = 0; i < n; ++i)
	{
		pos_in_post[po[i]] = i;
	}

	vector<pair<int,int>> tree(n, pair<int,int> {-2, -2});
	vector<int> par(n, -1);
	stack<int> s;
	s.push(pr[0]);
	for(int i = 1; i < n; ++i)
	{
		int cur = pr[i];
		int prec = s.top();
		if(pos_in_post[cur] < pos_in_post[prec])
		{
			tree[prec].first = cur;
			par[cur] = prec;
			s.push(cur);
		} else
		{
			while(pos_in_post[cur] > pos_in_post[s.top()])
			{
				s.pop();
			}
			tree[s.top()].second = cur;
			par[cur] = s.top();
			s.push(cur);
		}
	}

	int tmr = 0;
	auto stampa_simmetrica = [&] (auto self, int v) -> void
	{
		if(tree[v].first != -2)
		{
			self(self, tree[v].first);
			simm[tmr++] = v+1;
			self(self, tree[v].second);
		} else
		{
			simm[tmr++] = v+1;
		}
	};

	stampa_simmetrica(stampa_simmetrica, pr[0]);
}
