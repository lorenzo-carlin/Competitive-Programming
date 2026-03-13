#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Segment
{
    struct node
    {
        ll sum = 0;
        ll pre = 0;

        node() {}
        node(int val) {sum = val; pre = max(0, val);}
    };

    node unisci(node a, node b)
    {
        node res;
        res.sum = a.sum + b.sum;
        res.pre = max(a.pre, a.sum + b.pre);
        return res;
    }

    int n;
    vector<node> t;

    Segment(int _n, vector<int> a)
    {
        for(n = 1; n < _n; n <<= 1);
        t.resize(2*n);
        for(int i = 1; i < _n; ++i) t[i+n] = a[i];
        for(int i = n-1; i > 0; --i) t[i] = unisci(t[2*i], t[2*i+1]);
    }

    void update(int i, int tl, int tr, int p, int v)
    {
        if(p < tl || tr < p) return;
        if(tl == tr) t[i] = v;
        else
        {
            int tm = (tr + tl) / 2;
            update(2*i, tl, tm, p, v);
            update(2*i+1, tm+1, tr, p, v);
            t[i] = unisci(t[2*i], t[2*i+1]);
        }
    }

    void update(int p, int v)
    {
        update(1, 0, n-1, p, v);
    }

    ll _sum = 0, _pre = 0;
    
    void query(int i, int tl, int tr, int l, int r)
    {
        if(r < tl || tr < l) return;
        if(l <= tl && tr <= r)
        {
            _pre = max(_sum + t[i].pre, _pre);
            _sum += t[i].sum;
        } else
        {
            int tm = (tl + tr) / 2;
            query(2*i, tl, tm, l, r);
            query(2*i+1, tm+1, tr, l, r);
        }
    }

    ll query(int l, int r)
    {
        _sum = 0;
        _pre = 0;
        query(1, 0, n-1, l, r);
        return _pre;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(auto &i: a) cin >> i;

    Segment st = Segment(n, a);
    
    for(int i = 0; i < q; ++i)
    {
        int type, x, y; cin >> type >> x >> y;
        if(type == 1) st.update(x-1, y);
        else cout << st.query(x-1, y-1) << "\n";
    }
}