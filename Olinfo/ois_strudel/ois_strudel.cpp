#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int INF = INT_MAX;

struct Segment
{
	int n;
	vector<int> t;

	Segment(int _n, vector<int> a)
	{
		for(n = 1; n < _n; n <<= 1);
		t.resize(2*n, -INF);
		for(int i = 0; i < _n; ++i) t[i+n] = a[i];
		for(int i = n-1; i > 0; i--) t[i] = min(t[2*i], t[2*i+1]);
	}

	void update(int i, int tl, int tr, int p, int v)
	{
		if(p < tl || tr < p) return;
		if(tl == tr) t[i] = v;
		else
		{
			int tm = (tl + tr) / 2;
			update(2*i, tl, tm, p, v);
			update(2*i+1, tm+1, tr, p, v);
			t[i] = min(t[2*i], t[2*i+1]);
		}
	}

	void update(int p, int v)
	{
		update(1, 0, n-1, p, v);
	}

	int query(int i, int tl, int tr, int l, int r, int x)
	{
		if(r < tl || tr < l || t[i] > x) return -1;
		if(tl == tr) return i;
		int tm = (tl + tr) / 2;
		int sx = query(2*i, tl, tm, l, r, x);
		if(sx == -1) return query(2*i+1, tm+1, tr, l, r, x);
		else return sx;
	}

	int query(int l, int r, int x)
	{
		return query(1, 0, n-1, l, r, x);
	}

	void print()
	{
		for(int i = 0; i < 2*n; ++i)
		{
			cout << i << ": " << t[i] << "\n";
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; cin >> n;
	vector<pair<int,int>> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i].first;
	for(int i = 0; i < n; ++i) cin >> v[i].second;

	vector<int> ps;
	ps.push_back(0);
	for(int i = 0; i < n; ++i)
	{
		ps.push_back(ps.back() + (v[i].second-v[i].first));
	}

	Segment seg = Segment(n+1, ps);
	int mx = 0;
	for(int i = 0; i < n; ++i)
	{
		int lim = seg.query(0, i+1, ps[i+1]);
		if(lim == -1) continue;
		mx = max(mx, i+1-(lim-seg.n));
	}

	cout << mx << "\n";
}
