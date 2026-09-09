#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val = 0;
    bool lazy = false;
};

struct Segment
{
    int n;
    vector<node> t;

    Segment(int _n)
    {
        for(n = 1; n < _n; n <<= 1);
        t.resize(2*n);
    }

    void propagate(int i, int tl, int tr)
    {
        if(t[i].lazy)
        {
            t[i].val = (tr - tl + 1) - t[i].val;
            if(tl != tr)
            {
                t[2*i].lazy = !t[2*i].lazy;
                t[2*i+1].lazy = !t[2*i+1].lazy;
            }
            t[i].lazy = false;
        }
    }

    void update(int i, int tl, int tr, int l, int r)
    {
        propagate(i, tl, tr);
        if(r < tl || tr < l) return;
        if(l <= tl && tr <= r)
        {
            t[i].lazy = !t[i].lazy;
            propagate(i, tl, tr);
            return;
        }
        int tm = (tl + tr) / 2;
        update(2*i, tl, tm, l, r);
        update(2*i+1, tm+1, tr, l, r);
        t[i].val = t[2*i].val + t[2*i+1].val;
    }

    void update(int l, int r)
    {
        update(1, 0, n-1, l, r);
    }

    int query(int i, int tl, int tr, int l, int r)
    {
        propagate(i, tl, tr);
        if(r < tl || tr < l) return 0;
        if(l <= tl && tr <= r) return t[i].val;
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
    
    int n, q; cin >> n >> q;
    Segment st = Segment(n);
    for(int i = 0; i < q; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        if(a == 0) st.update(b, c);
        else if(a == 1) cout << st.query(b, c) << "\n";
    }
}