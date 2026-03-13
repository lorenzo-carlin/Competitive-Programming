#include <bits/stdc++.h>
using namespace std;

struct Segment
{
    int n;
    vector<int> t;

    Segment(int _n, vector<int> a)
    {
        for(n = 1; n < _n; n <<= 1);
        t.resize(2*n);
        for(int i = 0; i < _n; ++i) t[i+n] = a[i];
        for(int i = n-1; i > 0; --i) t[i] = min(t[2*i], t[2*i+1]);
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
        else
        {
            int tm = (tl + tr) / 2;
            return min(query(2*i, tl, tm, l, r), query(2*i+1, tm+1, tr, l, r));
        }
    }

    int query(int l, int r)
    {
        return query(1, 0, n-1, l, r);
    }
};

int salta(int n, vector<int> s, vector<int> a, vector<int> b)
{
    vector<int> dp(n+1);
    Segment st = Segment(n+1, dp);
    st.update(n, 0);
    for(int i = n-1; i >= 0; --i)
    {
        dp[i] = max(s[i], st.query(i+a[i], i+b[i]));
        st.update(i, dp[i]);
    }
    return dp[0];
}


int main()
{
    int n; cin >> n;
    vector<int> s(n), a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> s[i] >> a[i] >> b[i];
    cout << salta(n, s, a, b) << "\n";
}