#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> verifica(int n, vector<int> t)
{
	priority_queue<pair<int,int>> pq;
	for(int i = 0; i < n; ++i) pq.push({-t[i], i});

	int timer = 0, ind = pq.top().second;
	int l = ind, r = ind;
	pq.pop();
	vector<int> ordine;
	vector<bool> vis(n, false);
	vis[ind] = true;
	ordine.push_back(ind);
	while(!pq.empty())
	{
		int anno = -pq.top().first;
		int pos  =  pq.top().second;
		pq.pop();

		if(vis[pos]) continue;

		if(pos > r)
		{
			if(timer + (pos - r) <= anno)
			{
				for(int i = r+1; i <= pos; i++)
				{
					ordine.push_back(i);
					vis[i] = true;
				}
				timer += (pos - r);
				r = pos;
			} else
			{
				return {};
			}
		} else if(pos < l)
		{
			if(timer + (l - pos) <= anno)
			{
				for(int i = l-1; i >= pos; i--)
				{
					ordine.push_back(i);
					vis[i] = true;
				}
				timer += (l - pos);
				l = pos;
			} else
			{
				return {};
			}
		}
	}

	return ordine;
}
