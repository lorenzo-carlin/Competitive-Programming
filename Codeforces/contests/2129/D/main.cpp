#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Segment
{
	int n;
	vector<int> t;

	Segment() {}

	Segment(int _n)
	{
		for(n = 1; n < _n; n <<= 1);
		t.resize(2*n, 0);
	}

	void update(int i, int tl, int tr, int p, int v)
	{
		if(p < tl || tr < p) return;
		if(p == tl && p == tr) t[i] = v;
		else
		{
			int tm = (tl + tr) / 2;
			update(2*i, tl, tm, p, v);
			update(2*i+1, tm+1, tr, p, v);
			t[i] = t[2*i] + t[2*i+1];
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
		return query(2*i, tl, tm, l, r) + query(2*i+1, tm+1, tr, l, r);
	}

	int query(int l, int r)
	{
		return query(1, 0, n-1, l, r);
	}
};

void solve()
{
	int n; cin >> n;
	vector<pair<int,int>> v(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(begin(v), end(v));

	int tot = 0;
	Segment seg = Segment(n);
	for(int i = 0; i < n; ++i)
	{
		int x = v[i].second;
		int sx = x - seg.query(0, x);
		int dx = n - 1 - x - seg.query(x, n-1);
		tot += min(sx, dx);
		seg.update(x, 1);
	}

	cout << tot << "\n";
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int t; cin >> t;
	while(t--) solve();
}
