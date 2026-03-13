#include <bits/stdc++.h>
using namespace std;

struct Segment
{
    int n;
    vector<int> t;

    Segment(int _n, vector<int> a)
    {
        for(n = 1; n < _n; n <<= 1);
        t.resize(2*n, -1e9);
        for(int i = 0; i < _n; ++i) t[i+n] = a[i];
        for(int i = n-1; i >= 0; --i) t[i] = max(t[2*i], t[2*i+1]);
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
        }
    }

    void update(int l, int r)
    {
        update(1, 0, n-1, l, r);
    }

    int query(int i, int tl, int tr, int l, int r, int x)
    {
        if(r < tl || tr < l) return -1;
        if(t[i] < x) return -1;
        if(tl == tr) return tl;
        int tm = (tl + tr) / 2;
        int sx = query(2*i, tl, tm, l, r, x);
        if(sx != -1) return sx;
        return query(2*i+1, tm+1, tr, l, r, x);
    }

    int query(int l, int r, int x)
    {
        return query(1, 0, n-1, l, r, x);
    }
};

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for(auto &el: a) cin >> el;

    Segment st = Segment(n, a);
    int q; cin >> q;
    for(int i = 0; i < q; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        cout << st.query(a, b, c) << "\n";
    }
}