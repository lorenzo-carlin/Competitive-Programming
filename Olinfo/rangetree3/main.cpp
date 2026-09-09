#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node
{
    int pre = -1e9;
    int tot = 0;
    int suf = -1e9;
    int sub_max = -1e9;
};

node unisci(node a, node b)
{
    node res;
    res.tot = a.tot + b.tot;
    res.pre = max(a.pre, a.tot + b.pre);
    res.suf = max(b.suf, b.tot + a.suf);
    res.sub_max = max(max(a.sub_max, b.sub_max), a.suf + b.pre);
    return res;
}

struct Segment
{
    int n;
    vector<node> t;

    Segment(int _n, vector<int> a)
    {
        for(n = 1; n <= _n; n <<= 1);
        t.resize(2*n);
        for(int i = 0; i < _n; i++) t[i+n].pre = t[i+n].tot = t[i+n].suf = t[i+n].sub_max = a[i];
        for(int i = n-1; i > 0; i--) t[i] = unisci(t[2*i], t[2*i+1]);
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
            t[i] = unisci(t[2*i], t[2*i+1]);
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
        return unisci(query(2*i, tl, tm, l, r), query(2*i+1, tm+1, tr, l, r));
    }

    node query(int l, int r)
    {
        return query(1, 0, n-1, l, r);
    }
};


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<int> a(n);
    for(auto &el: a) cin >> el;
    
    Segment st = Segment(n, a);

    int q; cin >> q;
    for(int i = 0; i < q; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        if(a == 0) st.update(b-1, c);
        else cout << st.query(b-1, c-1).sub_max << "\n";
    }
}