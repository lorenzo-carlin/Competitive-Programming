#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Segment
{
    int n;
    vector<ll> seg;

    Segment(int _n, vector<int> a)
    {
        for(n = 1; n <= _n; n <<= 1);
        seg.resize(2*n);
        for(int i = 0; i < _n; ++i) seg[i+n] = a[i];
        for(int i = n-1; i > 0; i--) seg[i] = seg[2*i] + seg[2*i+1];
    }

    void update(int i, int tl, int tr, int p, int v)
    {
        if(p < tl || tr < p) return;
        if(tl == tr) seg[i] = v;
        else
        {
            int tm = (tl + tr) / 2;
            update(2*i, tl, tm, p, v);
            update(2*i+1, tm+1, tr, p, v);
            seg[i] = seg[2*i] + seg[2*i+1];
        }
    }

    void update(int p, int v)
    {
        update(1, 0, n-1, p, v);
    }

    ll query(int i, int tl, int tr, int l, int r)
    {
        if(r < tl || tr < l) return 0;
        if(l <= tl && tr <= r) return seg[i];
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
	vector<vector<int>> adj(n);
	vector<int> val(n), ord;
    for(int i = 0; i < n; ++i)
    {
        cin >> val[i];
    }
    for(int i = 0, a, b; i < n-1; ++i)
    {
        cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
	
	vector<int> in(n), out(n);
	int timer = 0;
	auto dfs = [&](auto&& self, int node, int p) -> void
	{
		in[node] = timer;
		for(int v: adj[node])
		{
			if(p == v) continue;
			self(self, v, node);
		}
		out[node] = ++timer;
		ord.push_back(node);
	};

	dfs(dfs, 0, -1);

    vector<int> v(n);
    for(int i = 0; i < n; ++i)
    {
        v[i] = val[ord[i]];
    }

    Segment s = Segment(n, v);

    for(int i = 0; i < q; ++i)
    {
        int type; cin >> type;
        if(type == 1)
        {
            int a, b; cin >> a >> b; --a;
            s.update(out[a]-1, b);
        } else
        {
            int a; cin >> a; --a;
            cout << s.query(in[a], out[a]-1) << "\n";
        }
    }
}
