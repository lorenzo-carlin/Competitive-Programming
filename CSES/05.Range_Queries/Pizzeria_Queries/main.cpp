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
        t.resize(2*n);
        for(int i = 0; i < _n; ++i) t[i+n] = a[i];
        for(int i = n-1; i >= 0; i--) t[i] = min(t[2*i], t[2*i+1]);
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

    int query(int i, int tl, int tr, int l, int r)
    {
        if(r < tl || tr < l) return 1e9;
        if(l <= tl && tr <= r) return t[i];
        int tm = (tl + tr) / 2;
        return min(query(2*i, tl, tm, l, r), query(2*i+1, tm+1, tr, l, r));
    }

    int query(int l, int r)
    {
        return query(1, 0, n-1, l, r);
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    vector<int> v(n), a(n), b(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
        a[i] = v[i] + i;
        b[i] = v[i] - i;
    }

    Segment s1 = Segment(n, a);
    Segment s2 = Segment(n, b);

    for(int i = 0; i < q; ++i)
    {
        int t; cin >> t;
        if(t == 1)
        {
            int x, y; cin >> x >> y;
            x--;
            s1.update(x, y+x);
            s2.update(x, y-x);
        } else
        {
            int x; cin >> x;
            x--;
            int sol1 = s1.query(x, n-1) - x;
            int sol2 = s2.query(0, x) + x;
            cout << min(sol1, sol2) << "\n";
        }
    }

}