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
		t.resize(2*n, 0);
		for(int i = 0; i < _n; ++i) t[i+n] = a[i];
		for(int i = n-1; i > 0; i--) t[i] = t[2*i]+t[2*i+1];
	}

	void update(int i, int tl, int tr, int p, int v)
	{
		if(p < tl || tr < p) return;
		if(p == tl && tr == p) t[i] += v;
		else
		{
			int tm = (tr + tl) / 2;
			update(2*i, tl, tm, p, v);
			update(2*i+1, tm+1, tr, p, v);
			t[i] = t[2*i]+t[2*i+1];
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
		return query(2*i, tl, tm, l, r)+query(2*i+1, tm+1, tr, l, r);
	}

	int query(int l, int r)
	{
		return query(1, 0, n-1, l, r);
	}

	void print()
	{
		cout << "------------------\n";
		for(int i = 1; i < 2*n; ++i)
		{
			cout << i << ": " << t[i] << "\n";
		}
		cout << "\n";
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n);
	for(int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> inizio(n, 1e9), fine(n, 1e9);
	queue<int> q;
	q.push(0);
	inizio[0] = 0;
	while(!q.empty())
	{
		int v = q.front();
		q.pop();

		for(int u: adj[v])
		{
			if(inizio[u] >= inizio[v]+1)
			{
				inizio[u] = inizio[v]+1;
				q.push(u);
			}
		}
	}
	q.push(n-1);
	fine[n-1] = 0;
	while(!q.empty())
	{
		int v = q.front();
		q.pop();

		for(int u: adj[v])
		{
			if(fine[u] >= fine[v]+1)
			{
				fine[u] = fine[v]+1;
				q.push(u);
			}
		}
	}

	int D = fine[0];
	vector<int> occ(n, 0);
	for(int i = 0; i < n; ++i)
	{
		occ[fine[i]]++;
	}

	Segment seg = Segment(n, occ);

	ll ans = 0;
	for(int i = 0; i < n; ++i)
	{
		int lim = max(0, D - inizio[i] - 2);
		ans += seg.query(0, lim);
		cout << i << ": " << ans << "\n";
	}

	cout << ans << "\n";

	ans = n*(n-1)/2 - ans/2 - m;
	cout << ans << "\n";
}
