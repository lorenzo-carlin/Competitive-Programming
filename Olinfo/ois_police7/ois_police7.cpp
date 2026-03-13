#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Segment // Segment MAX
{
    int n;
    vector<pair<int,int>> t;

    Segment() {}
    Segment(int _n)
    {
        for(n = 1; n < _n; n <<= 1);
        t.resize(2*n, {0, -1});
    }

    void update(int i, int tl, int tr, int p, int v)
    {
        if(p < tl || tr < p) return;
        if(p == tl && p == tr) t[i] = {v, i-n};
        else
        {
            int tm = (tl + tr) / 2;
            update(2*i, tl, tm, p, v);
            update(2*i+1, tm+1, tr, p, v);

            if(t[2*i].first > t[2*i+1].first) t[i] = t[2*i];
            else if(t[2*i].first < t[2*i+1].first) t[i] = t[2*i+1];
            else t[i] = {t[2*i].first, max(t[2*i].second, t[2*i+1].second)};
        }
    }

    void update(int p, int v)
    {
        update(1, 0, n-1, p, v);
    }

    // {vmax, pos}
    pair<int,int> query(int i, int tl, int tr, int l, int r) // ritorna la posizione del numero maggiore in [l, r], in caso di parità a DX
    {
        if(r < tl || tr < l) return {0, -1};
        if(l <= tl && tr <= r) return t[i];

        int tm = (tl + tr) / 2;
        pair<int,int> a = query(2*i, tl, tm, l, r);
        pair<int,int> b = query(2*i+1, tm+1, tr, l, r);

        if(a.first > b.first) return a;
        else if(b.first > a.first) return b;
        else return {a.first, max(a.second, b.second)};
    }

    pair<int,int> query(int l, int r)
    {
        return query(1, 0, n-1, l, r);
    }

    void print()
    {
        for(int i = 0; i < 2*n; ++i)
        {
            cout << i << ": " << t[i].first << " " << t[i].second << "\n";
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    vector<int> v(n);
    for(int &i: v) cin >> i;

    Segment seg = Segment(n);
    for(int i = 0; i < n; ++i)
    {
        seg.update(i, v[i]);
    }


    for(int i = 0, a, b; i < q; ++i)
    {
        cin >> a >> b;
        seg.update(a, b);
        pair<int,int> p = seg.query(0, n-1);
        int pos = p.second;
        ll ans = 0;
        while(pos != n-1)
        {
            //cout << pos << " ";
            ans += p.first;
            p = seg.query(pos+1, n-1);
            pos = p.second;
        }
        ans += p.first;

        cout << ans << "\n";
    }
}