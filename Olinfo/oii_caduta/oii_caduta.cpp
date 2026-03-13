#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool valid(vector<int> v)
{
	int last_to_fall = v[0]-1;
	bool cond = true;
	for(int i = 1; i < v.size(); ++i)
	{
		if(i > last_to_fall)
		{
			cond = false;
		}
		last_to_fall = max(last_to_fall, (v[i]-1)+i);
	}
	return cond;
}

stato_t correggi(int N, int altezze[], coppia_t* scambio)
{
	vector<int> v(N);
	for(int i = 0; i < N; ++i) v[i] = altezze[i];

	if(valid(v)) return OK;
	if(N > 5e3) return IMPOSSIBILE;
	for(int i = 0; i < N; ++i)
	{
		for(int j = i+1; j < N; ++j)
		{
			swap(v[i], v[j]);
			if(valid(v))
			{
				scambio->domino1 = i;
				scambio->domino2 = j;
				return RISOLTO;
			}
			swap(v[i], v[j]);
		}
	}
	return IMPOSSIBILE;
}
