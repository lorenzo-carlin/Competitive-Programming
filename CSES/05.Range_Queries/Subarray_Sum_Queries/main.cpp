#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e15;

struct node
{
    ll pre = -INF;
    ll tot = 0;
    ll suf = -INF;
    ll sub_max = -INF;
};

node merge(node a, node b)
{
    node res;
    res.tot = (a.tot + b.tot);
    res.pre = max(a.pre, a.tot+b.pre);
    res.suf = max(b.suf, a.suf+b.tot);
    res.sub_max = max(max(a.sub_max, b.sub_max), a.suf+b.pre);
    return res;
}

struct Segment
{
    int n;
    vector<node> t;

    Segment(int _n, vector<int> a)
    {
        for(n = 1; n < _n; n <<= 1);
        t.resize(2*n);
        for(int i = 0; i < _n; ++i) t[n+i].pre = t[n+i].tot = t[n+i].suf = t[n+i].sub_max = a[i];
        for(int i = n-1; i >= 0; i--) t[i] = merge(t[2*i], t[2*i+1]);
    }

    void update(int i, int tl, int tr, int p, int v)
    {
        if(p < tl || tr < p) return;
        if(tl == tr) t[i].pre = t[i].tot = t[i].suf = t[i].sub_max = v;
        else
        {
            int tm = (tl + tr) / 2;
            update(2*i, tl, tm, p, v);
            update(2*i+1, tm+1, tr, p, v);
            t[i] = merge(t[2*i], t[2*i+1]);
        }
    }

    void update(int p, int v)
    {
        update(1, 0, n-1, p, v);
    }

    node query(int i, int tl, int tr, int l, int r)
    {
        if(r < tl || tr < l) return {};
        if(l <= tl && tr <= r) return t[i];
        int tm = (tl + tr) / 2;
        return merge(query(2*i, tl, tm, l, r), query(2*i+1, tm+1, tr, l, r));
    }

    node query(int l, int r)
    {
        return query(1, 0, n-1, l, r);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<int> v(n);
    for(auto &i: v) cin >> i;

    Segment st = Segment(n, v);
    ll vuoto = 0;
    for(int i = 0; i < m; ++i)
    {
        int k, x; cin >> k >> x;
        k--;
        st.update(k, x);
        cout << max(st.query(0, n-1).sub_max, vuoto) << "\n";
    }
}