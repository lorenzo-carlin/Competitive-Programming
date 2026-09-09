#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
- somma di [l. r)
- aggiungere x a tutto gli elementi in [l, r) -> lazy propagation
- settare a x tutti gli elementi in [l, r) -> (+ elimino un'eventuale lazy in sospeso)
- minimo in [l, r)
- elemento più a sinistra <= x
*/

struct node
{
	ll sum = 0;
	ll mn = 1e9;
	ll lazy = 0;
	bool set = false;
	ll set_value;

	node() {}
	node(ll v) : sum(v), mn(v) {}
};

struct Segment
{
	int n;
	vector<node> t;

	node merge(node a, node b)
	{
		node res;
		res.sum = a.sum + b.sum;
		res.mn = min(a.mn, b.mn);
		return res;
	}

	Segment() {}
	Segment(int _n, vector<ll> a)
	{
		for(n = 1; n <= _n; n <<= 1);
		t.resize(2*n);
		for(int i = 0; i < _n; ++i) t[i+n] = node(a[i]);
		for(int i = n-1; i > 0; i--) t[i] = merge(t[2*i], t[2*i+1]);
	}

	void propaga(int i, int tl, int tr)
	{
		if(t[i].set)
		{
			t[i].sum = (tr - tl + 1) * t[i].set_value;
			t[i].mn = t[i].set_value;
			if(tl != tr)
			{
				t[2*i].set = t[2*i+1].set = true;
				t[2*i].set_value = t[2*i+1].set_value = t[i].set_value;
			}
			t[i].set = false;
			t[i].set_value = 0;
			t[i].lazy = 0;
		} else if(t[i].lazy)
		{
			t[i].sum += (tr - tl + 1) * t[i].lazy;
			t[i].mn += t[i].lazy;
			if(tl != tr) t[2*i].lazy = t[2*i+1].lazy = t[i].lazy;
			t[i].lazy = 0;
		}
	}

	ll get_sum(int i, int tl, int tr, int l, int r)
	{
		propaga(i, tl, tr);
		if(r < tl || tr < l) return 0;
		if(l <= tl && tr <= r) return t[i].sum;
		int tm = (tl + tr) / 2;
		return get_sum(2*i, tl, tm, l, r)+get_sum(2*i+1, tm+1, tr, l, r);
	}

	void add(int i, int tl, int tr, int l, int r, ll x)
	{
		propaga(i, tl, tr);
		if(r < tl || tr < l) return;
		if(l <= tl && tr <= r)
		{
			t[i].lazy = x;
			propaga(i, tl, tr);
		} else
		{
			int tm = (tl + tr) / 2;
			add(2*i, tl, tm, l, r, x);
			add(2*i+1, tm+1, tr, l, r, x);
			t[i] = merge(t[2*i], t[2*i+1]);
		}
		// t[i] = merge(t[2*i], t[2*i+1]);
	}

	void set_range(int i, int tl, int tr, int l, int r, ll x)
	{
		propaga(i, tl, tr);
		if(r < tl || tr < l) return;
		if(l <= tl && tr <= r)
		{
			t[i].set = true;
			t[i].set_value = x;
			propaga(i, tl, tr);
		} else
		{
			int tm = (tl + tr) / 2;
			set_range(2*i, tl, tm, l, r, x);
			set_range(2*i+1, tm+1, tr, l, r, x);
			t[i] = merge(t[2*i], t[2*i+1]);
		}
		// t[i] = merge(t[2*i], t[2*i+1]);
	}
	
	ll get_min(int i, int tl, int tr, int l, int r)
	{
		propaga(i, tl, tr);
		if(r < tl || tr < l) return 1e9;
		if(l <= tl && tr <= r) return t[i].mn;
		int tm = (tl + tr) / 2;
		return min(get_min(2*i, tl, tm, l, r), get_min(2*i+1, tm+1, tr, l, r));
	}

	ll lower_bound(int l, int r, ll x)
	{
		return -1;
	}
};

Segment seg;
int N;

void init(vector<ll> a)
{
	seg = Segment(a.size(), a);
	N = seg.n;
}

ll get_sum(int l, int r)
{
	return seg.get_sum(1, 0, N-1, l, r-1);
}

void add(int l, int r, ll x)
{
	seg.add(1, 0, N-1, l, r-1, x);
}

void set_range(int l, int r, ll x)
{
	seg.set_range(1, 0, N-1, l, r-1, x);
}

ll get_min(int l, int r)
{
	return seg.get_min(1, 0, N-1, l, r-1);
}

ll lower_bound(int l, int r, ll x)
{
	return seg.lower_bound(l, r, x);
}
