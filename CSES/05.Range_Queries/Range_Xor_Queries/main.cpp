#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Segment
{
    int n;
    vector<int> t;
    
    Segment(int _n, vector<int> a)
    {
        for(n = 1; n < _n; n<<=1);
        t.resize(2*n);
        for(int i = 0; i < _n; ++i) t[i+n] = a[i];
        for(int i = n-1; i > 0; --i) t[i] = t[2*i] ^ t[2*i+1];
    }

    void update(int i, int tl, int tr, int p, int v)
    {
        if(p < tl || tr < p) return;
        if(tl == tr)
        {
            t[tl] = v;
        } else
        {
            int tm = (tl + tr) / 2;
            update(i*2, tl, tm, p, v);
            update(i*2+1, tm+1, tr, p, v);
            t[i] = t[2*i] ^ t[2*i+1];
        }
    }

    void update(int p, int v)
    {
        update(1, 0, n-1, p, v);
    }

    int query(int i, int tl, int tr, int l, int r)
    {
        if(r < tl || tr < l) return 0;
        if(l <= tl && tr <= r) return t[i];
        else
        {
            int tm = (tr + tl) / 2;
            return query(i*2, tl, tm, l, r) ^ query(i*2+1, tm+1, tr, l, r);
        }
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
    vector<int> v(n);
    for(auto &i: v) cin >> i;
    Segment st = Segment(n, v);
    for(int i = 0; i < q; ++i)
    {
        int a, b; cin >> a >> b; a--; b--;
        cout << st.query(a, b) << "\n";
    }
}