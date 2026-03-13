#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Segment
{
	int n;
	vector<int> t;

	Segment() {}
	Segment(int _n, vector<int> a)
	{
		for(n = 1; n < _n; n <<= 1);
		t.resize(2*n);
		for(int i = 0; i < _n; ++i) t[i+n] = a[i];
		for(int i = n-1; i >= 0; i--) t[i] = max(t[2*i], t[2*i+1]);
	}

	void update(int i, int tl, int tr, int p, int v)
	{
		if(p < tl || tr < p) return;
		if(p == tl && tr == p) t[i] = v;
		else
		{
			int tm = (tl + tr) / 2;
			update(2*i, tl, tm, p, v);
			update(2*i+1, tm+1, tr, p, v);
			t[i] = max(t[2*i], t[2*i+1]);
		}
	}

	void update(int p, int v)
	{
		update(1, 0, n-1, p, v);
	}

	int query(int i, int tl, int tr, int l, int r)
	{
		if(r < tl || tr < l) return 0;
		if(l <= tl && tr <= r) return t[i];
		int tm = (tl + tr) / 2;
		return max(query(2*i, tl, tm, l, r), query(2*i+1, tm+1, tr, l, r));
	}

	int query(int l, int r)
	{
		return query(1, 0, n-1, l, r);
	}
};

Segment seg;
int _n;

void inizia(int n, vector<int> a)
{
	seg = Segment(n, a);
	_n = n;
}

void aggiorna(int p, int v)
{
	seg.update(p, v);
}

int massimo(int l, int r)
{
	return seg.query(l, r);
}
