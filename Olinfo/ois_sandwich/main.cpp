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
		t.resize(2*n, -1);
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
			t[i] = max(t[2*i], t[2*i+1]);
		}
	}

	void update(int p, int v)
	{
		update(1, 0, n-1, p, v);
	}

	int query(int i, int tl, int tr, int l, int r)
	{
		if(r < tl || tr < l) return -1e9;
		if(l <= tl && tr <= r) return t[i];
		int tm = (tl + tr) / 2;
		return max(query(2*i, tl, tm, l, r), query(2*i+1, tm+1, tr, l, r));
	}

	int query(int x)
	{
		return query(1, 0, n-1, x, n-1);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> v(n);
	for(auto &i: v) cin >> i;

	vector<pair<ll,int>> ps(n+1, {0, 0}), PS;
	for(int i = 0; i < n; ++i)
		ps[i+1] = {ps[i].first+v[i], i+1};
    PS = ps;
	sort(begin(ps), end(ps));
	vector<ll> val(n+1), pos(n+1);
	for(int i = 0; i <= n; ++i)
	{
		val[i] = ps[i].first;
		pos[ps[i].second] = i;
	}
	
	Segment seg = Segment(n+1);

	vector<int> dp(n+1, -1);
	dp[n] = 0;
	seg.update(pos[n], 0);
	for(int i = n-1; i >= 0; i--)
	{
        ll tmp = PS[i].first;
        int x = upper_bound(begin(val), end(val), tmp) - begin(val);
		int mx = seg.query(x);
		if(mx != -1)
		{
			dp[i] = mx+1;
			seg.update(pos[i], dp[i]);
		}
	}

	cout << dp.front() << "\n";
}


