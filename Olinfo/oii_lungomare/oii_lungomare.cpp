#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int percorri(int n, int l, int d[], int p[])
{

	auto possible = [&](int val) -> void
	{





	int l = 0, r = l;
	while(l < r)
	{
		int m = (l+r) / 2;
		if(possible(m))
		{
			l = m+1;
		} else
		{
			r = m;
		}
	}

	if(possible(r)) return r;
	else return r-1;
}
