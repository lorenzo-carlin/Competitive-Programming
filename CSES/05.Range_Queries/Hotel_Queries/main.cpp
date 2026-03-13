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
        if(tl == tr)
        {
            t[i] -= v;
            return;
        }
        int tm = (tl + tr) / 2;
        update(2*i, tl, tm, p, v);
        update(2*i+1, tm+1, tr, p, v);
        t[i] = max(t[2*i], t[2*i+1]);
    }

    void update(int p, int v)
    {
        update(1, 0, n-1, p, v);
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
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(auto &i: a) cin >> i;

    Segment st = Segment(n, a);
    for(int i = 0; i < m; ++i)
    {
        int num; cin >> num;
        int sol = st.query(0, n-1, num);
        if(sol == -1) cout << "0 ";
        else
        {
            cout << sol+1 << " ";
            st.update(sol, num);
        }
    }
}