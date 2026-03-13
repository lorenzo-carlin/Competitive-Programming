#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int INF = 1e9;

struct Segment
{
    int n;
    vector<int> t;

    Segment() {}
    Segment(int _n)
    {
        for(n = 1; n < _n; n <<= 1);
        t.resize(2*n, INF);
    }

    void update(int i, int tl, int tr, int p, int v)
    {
        if(p < tl || tr < p) return;
        if(tl == tr && tl == p) t[i] = v;
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
        if(r < tl || tr < l) return INF;
        if(l <= tl && tr <= r) return t[i];
        int tm = (tl + tr) / 2;
        return min(query(2*i, tl, tm, l, r), query(2*i+1, tm+1, tr, l, r));
    }

    int query(int l, int r)
    {
        return query(1, 0, n-1, l, r);
    }

    void print()
    {
        for(int i = n; i < 2*n; i++)
        {
            cout << t[i] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> w(n);
    for(int &i: w) cin >> i;

    vector<int> ps(n+1, 0);
    for(int i = n-1; i >= 0; i--)
        ps[i] = ps[i+1] + w[i];

    int m; cin >> m;
    vector<int> k(m), t(m);
    for(int &i: k) cin >> i;
    for(int &i: t) cin >> i;

    vector<int> mxw(n+1, 0);

    for(int i = 0; i < m; i++)
        mxw[k[i]] = max(mxw[k[i]], t[i]);

    for(int i = n-1; i >= 0; i--)
        mxw[i] = max(mxw[i], mxw[i+1]);

    auto found = [&] (int l, int r) -> bool
    {
        int nr = r-l+1;
        int we = ps[l]-ps[r+1];

        return (mxw[nr] >= we);
    };

    Segment seg = Segment(n+1);
    vector<int> dp(n, 0);
    seg.update(n, 0);

    for(int i = n-1; i >= 0; i--)
    {
        // faccio la binary search su [i, n-1]
        int l = i, r = n-1;
        while(r - l > 1)
        {
            int m = (l + r) / 2;
            if(found(i, m))
                l = m;
            else
                r = m;
        }

        int firstFalse = l;
        if(found(i, r))
            firstFalse = r+1;
        else if(found(i, l))
            firstFalse = r;

        dp[i] = seg.query(i, firstFalse)+1;
        seg.update(i, dp[i]);
    }

    cout << dp[0] << "\n";
}
