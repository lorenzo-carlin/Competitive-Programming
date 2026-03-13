#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Segment
{
	int n;
	vector<ll> t;

	Segment() {}
	Segment(int _n)
	{
		for(n = 1; n < _n; n <<= 1);
		t.resize(2*n, 0);
	}

	void update(int i, int tl, int tr, int p, ll v)
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

	void update(int p, ll v)
	{
		update(1, 0, n-1, p, v);
	}

	ll query(int i, int tl, int tr, int l, int r)
	{
		if(r < tl || tr < l) return -1;
		if(l <= tl && tr <= r) return t[i];
		int tm = (tl + tr) / 2;
		return max(query(2*i, tl, tm, l, r), query(2*i+1, tm+1, tr, l, r));
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

	int n; cin >> n;
	vector<int> h(n), a(n);
	for(auto &i: h) cin >> i;
	for(auto &i: a) cin >> i;

	Segment seg = Segment(n+1);

	ll ans = 0;
	vector<ll> dp(n);
	for(int i = 0; i < n; ++i)
	{
		dp[i] = (seg.query(0, h[i]) + a[i]);
		seg.update(h[i], dp[i]);
		ans = max(ans, dp[i]);
	}

	cout << ans << "\n";
}




	// dp[i] = soluzione massima per una sequenza non-decrescente che finisce in i
	// devo provare dp[j] per ogni j tale che h[j] <= h[i]
	// non posso farlo naive perché viene O(n^2)
	// mantendo il dp[i] massimo per ogni valore di i <= N in un segment tree
	// dp[i] = max(segment da 1 a h[i])
	

