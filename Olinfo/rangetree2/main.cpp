#include <bits/stdc++.h>
using namespace std;

struct node
{
    int zero = 1;
    int uno = 0;
    int due = 0;
    int lazy = 0;
};

struct Segment
{
    int n;
    vector<node> t;

    Segment(int _n)
    {
        for(n = 1; n < _n; n <<= 1);
        t.resize(2*n);
        for(int i = n-1; i >= 0; --i) t[i].zero = t[2*i].zero + t[2*i+1].zero;
    }

    void propagate(int i, int tl, int tr)
    {
        if(t[i].lazy % 3 == 1)
        {
            swap(t[i].zero, t[i].uno);
            swap(t[i].zero, t[i].due);
        }
        if(t[i].lazy % 3 == 2)
        {
            swap(t[i].zero, t[i].due);
            swap(t[i].zero, t[i].uno);
        }
        if(tl != tr)
        {
            t[2*i].lazy += t[i].lazy;
            t[2*i+1].lazy += t[i].lazy;
        }
        t[i].lazy = 0;
    }

    void update(int i, int tl, int tr, int l, int r)
    {
        propagate(i, tl, tr);
        if(r < tl || tr < l) return;
        if(l <= tl && tr <= r)
        {
            t[i].lazy += 1;
            propagate(i, tl, tr);
            return;
        }
        int tm = (tl + tr) / 2;
        update(2*i, tl, tm, l, r);
        update(2*i+1, tm+1, tr, l, r);
        t[i].zero = t[2*i].zero + t[2*i+1].zero;
        t[i].uno = t[2*i].uno + t[2*i+1].uno;
        t[i].due = t[2*i].due + t[2*i+1].due;
    }

    void update(int l, int r)
    {
        update(1, 0, n-1, l, r);
    }

    int query(int i, int tl, int tr, int l, int r)
    {
        propagate(i, tl, tr);
        if(r < tl || tr < l) return 0;
        if(l <= tl && tr <= r) return t[i].zero;
        int tm = (tl + tr) / 2;
        return query(2*i, tl, tm, l, r) + query(2*i+1, tm+1, tr, l, r);
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
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, q; cin >> n >> q;
    Segment st = Segment(n);
    for(int i = 0; i < q; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        if(a == 0) st.update(b, c);
        else if(a == 1) cout << st.query(b, c) << "\n";
    }
}