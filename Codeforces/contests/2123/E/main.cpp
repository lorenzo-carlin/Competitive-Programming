#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node
{
	int val = 0;
	int lazy = 0;
};

struct Segment
{
	int n;
	vector<node> t;

	Segment() {}
	Segment(int _n)
	{
		for(n = 1; n < _n; n <<= 1);
		t.resize(2*n);
	}

	void propagate(int i, int tl, int tr)
	{
		t[i].val += t[i].lazy*(tl-tr+1);
		
		if(tl < tr)
		{
			t[2*i].lazy += t[i].lazy;
			t[2*i+1].lazy += t[i].lazy;
		}

		t[i].lazy = 0;
	}

	void update(int i, int tl, int tr, int l, int r, int delta)
	{
		propagate(i, tl, tr);

		if(r < tl || tr < l) return;
		if(l <= tl && tr <= r)
		{
			t[i].lazy += delta;
			propagate(i, tl, tr);
		} else
		{
			int tm = (tl + tr) / 2;
			update(2*i, tl, tm, l, r, delta);
			update(2*i+1, tm+1, tr, l, r, delta);
			t[i].val = t[2*i].val + t[2*i+1].val;
		}
	}

	void update(int l, int r, int delta)
	{
		update(1, 0, n-1, l, r, delta);
	}

	int query(int i, int tl, int tr, int p)
	{
		propagate(i, tl, tr);

		if(p < tl || tr < p) return 0;
		if(tl == p && tr == p) return t[i].val;
		int tm = (tl + tr) / 2;
		return query(2*i, tl, tm, p) + query(2*i+1, tm+1, tr, p);
	}

	int query(int p)
	{
		return query(1, 0, n-1, p);
	}

	void print()
	{
		cout << "------------------------------\n";
		for(int i = 0; i < 2*n; ++i)
		{
			cout << i << ": " << t[i].val << " " << t[i].lazy << "\n";
		}
	}
};

void solve()
{
	int n; cin >> n;
	vector<int> v(n), cnt(n+1, 0);
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i];
		cnt[v[i]]++;
	}
	sort(begin(v), end(v));

	int pre = 0, dop = 0;
	Segment seg = Segment(n+1);
	// seg.print();
	for(int i = 0; i <= n; ++i)
	{
		int l = cnt[i];
		int r = n - pre + dop;
		if(l <= r) seg.update(l, r, 1);
		pre += cnt[i];
		dop += (cnt[i]-1);
		// seg.print();
		if(cnt[i] == 0) break;
	}

	for(int i = 0; i <= n; ++i)
	{
		cout << seg.query(i) << " ";
	}
	cout << "\n";
}		

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
