#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Segment
{
    int n;
    vector<int> t, a;

    Segment() {}

    Segment(int _n, vector<int> _a)
    {
        a = _a;
        for(n = 1; n < _n; n <<= 1);
        t.resize(2*n);
        for(int i = 0; i < _n; ++i) t[i+n] = 1;
        for(int i = n-1; i >= 0; --i) t[i] = t[2*i] + t[2*i+1];
    }

    pair<int,int> query(int i, int tl, int tr, int v)
    {
        if(t[i] < v) return {-1, -1};
        if(tl == tr) return {a[i-n], i-n};
        int tm = (tl + tr) / 2;
        pair<int,int> sx = query(2*i, tl, tm, v);
        if(sx != make_pair(-1, -1)) return sx;
        return query(2*i+1, tm+1, tr, v-t[2*i]);
    }

    pair<int,int> query(int v)
    {
        return query(1, 0, n-1, v);
    }

    void update(int i, int tl, int tr, int pos)
    {
        if(pos < tl || tr < pos) return;
        if(tl == tr) t[i] = 0;
        else
        {
            int tm = (tl + tr) / 2;
            update(2*i, tl, tm, pos);
            update(2*i+1, tm+1, tr, pos);
            t[i] = t[2*i] + t[2*i+1];
        }
    }

    void update(int pos)
    {
        update(1, 0, n-1, pos);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> a(n);
    for(auto &i: a) cin >> i;

    Segment st = Segment(n, a);

    for(int i = 0; i < n; ++i)
    {
        int q; cin >> q;
        pair<int,int> p = st.query(q);
        cout << p.first << " ";
        st.update(p.second);
    }
}