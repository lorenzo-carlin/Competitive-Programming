#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node
{
	ll val = 0;
	ll lazy = 0;
	bool set = false;
	ll set_value;
};

struct Segment
{
	int n; vector<node> t;

	Segment(int _n, vector<int> a)
	{
		for(n = 1; n < _n; n <<= 1);
		t.resize(2*n);
		for(int i = 0; i < _n; ++i) t[i+n].val = a[i];
		for(int i = n-1; i > 0; i--) t[i].val = t[2*i].val + t[2*i+1].val;
	}

	void propaga(int i, int tl, int tr)
	{
		if(t[i].set)
		{
			t[i].val = t[i].set_value*(tr-tl+1);
			t[i].set = false;

			if(tl != tr)
			{
				t[2*i].set = t[2*i+1].set = true;
				t[2*i].set_value = t[2*i+1].set_value = t[i].set_value;
				t[2*i].lazy = t[2*i+1].lazy = 0;
			}
		}
		if(t[i].lazy != 0)
		{
			t[i].val += t[i].lazy*(tr-tl+1);

			if(tl != tr)
			{
				t[2*i].lazy += t[i].lazy;
				t[2*i+1].lazy += t[i].lazy;
			}

			t[i].lazy = 0;
		}
	}

	void update_lazy(int i, int tl, int tr, int l, int r, int x)
	{
		propaga(i, tl, tr);

		if(r < tl || tr < l) return;
		if(l <= tl && tr <= r)
		{
			t[i].lazy += x;
			propaga(i, tl, tr);
		} else
		{
			int tm = (tl + tr) / 2;
			update_lazy(2*i, tl, tm, l, r, x);
			update_lazy(2*i+1, tm+1, tr, l, r, x);
			t[i].val = t[2*i].val + t[2*i+1].val;
		}
	}

	void update_lazy(int l, int r, int x)
	{
		update_lazy(1, 0, n-1, l, r, x);
	}

	void update_set(int i, int tl, int tr, int l, int r, int x)
	{
		propaga(i, tl, tr);

		if(r < tl || tr < l) return;
		if(l <= tl && tr <= r)
		{
			t[i].set = true;
			t[i].set_value = x;
			t[i].lazy = 0;
			propaga(i, tl, tr);
		} else
		{
			int tm = (tl + tr) / 2;
			update_set(2*i, tl, tm, l, r, x);
			update_set(2*i+1, tm+1, tr, l, r, x);
			t[i].val = t[2*i].val + t[2*i+1].val;
		}
	}

	void update_set(int l, int r, int x)
	{
		update_set(1, 0, n-1, l, r, x);
	}

	ll query(int i, int tl, int tr, int l, int r)
	{
		propaga(i, tl, tr);
		if(r < tl || tr < l) return 0;
		if(l <= tl && tr <= r) return t[i].val;
		int tm = (tl + tr) / 2;
		return query(2*i, tl, tm, l, r) + query(2*i+1, tm+1, tr, l, r);
	}

	ll query(int l, int r)
	{
		return query(1, 0, n-1, l, r);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q; cin >> n >> q;
	vector<int> a(n);
	for(int &i: a) cin >> i;

	Segment seg = Segment(n, a);

	for(int i = 0; i < q; ++i)
	{
		int type; cin >> type;
		if(type == 1)
		{
			int a, b, x; cin >> a >> b >> x;
			a--; b--;
			seg.update_lazy(a, b, x);
		} else if(type == 2)
		{
			int a, b, x; cin >> a >> b >> x;
			a--; b--;
			seg.update_set(a, b, x);
		} else
		{
			int a, b; cin >> a >> b;
			a--; b--;
			cout << seg.query(a, b) << "\n";
		}
	}
}
