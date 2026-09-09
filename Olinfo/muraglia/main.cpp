#include <bits/stdc++.h>
using namespace std;

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
            t[i] = max(t[2*i], t[2*i+1]);
        }
    }

    void update(int p, int v)
    {
        update(1, 0, n-1, p, v);
    }

    int query_sx(int i, int tl, int tr, int l, int r, int x)
    {
        if(r < tl || tr < l) return -1;
        if(t[i] <= x) return -1;
        if(tl == tr) return tl;
        int tm = (tl + tr) / 2;
        int sx = query_sx(2*i, tl, tm, l, r, x);
        if(sx != -1) return sx;
        return query_sx(2*i+1, tm+1, tr, l, r, x); 
    }

    int query_sx(int l, int r)
    {
        int x = t[l-1+n];
        return query_sx(1, 0, n-1, l, r, x);
    }

    int query_dx(int i, int tl, int tr, int l, int r, int x)
    {
        if(r < tl || tr < l) return -1;
        if(t[i] <= x) return -1;
        if(tl == tr) return tl;
        int tm = (tl + tr) / 2;
        int dx = query_dx(2*i+1, tm+1, tr, l, r, x);
        if(dx != -1) return dx;
        return query_dx(2*i, tl, tm, l, r, x);
    }

    int query_dx(int l, int r)
    {
        int x = t[r+1+n];
        return query_dx(1, 0, n-1, l, r, x);
    }

    void stampa()
    {
        for(int i = 1; i < t.size(); ++i)
        {
            cout << i << ": " << t[i] << "\n";
        }
    }
};

Segment st;
vector<int> h;
int n;

void inizializza(int N, vector<int> H)
{
    st = Segment(N, H);
    h = H;
    n = N;
}

void cambia(int x, int h)
{
    st.update(x, h);
}

pair<int,int> chiedi(int x)
{
    pair<int,int> res;
    res.first = st.query_dx(0, x-1);
    res.second = st.query_sx(x+1, n-1);
    if(res.first == -1) res.first = 0;
    if(res.second == -1) res.second = n-1;
    return res;
}
