#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 1e9;

struct Segment
{
    int n;
    vector<int> t;

    Segment() {}
    Segment(int _n, vector<int> a)
    {
        for(n = 1; n < _n; n <<= 1);
        t.resize(2*n, -inf);
        for(int i = 0; i < _n; i++)
            t[i+n] = a[i];
        for(int i = n-1; i > 0; i--)
            t[i] = max(t[2*i], t[2*i+1]);
    }

    int querymag(int i, int tl, int tr, int l, int r, int v)
    {
        if(r < tl || tr < l) return -1;
        if(tl == tr && t[i] > v) return i-n;
        int tm = (tl + tr) / 2;
        int tmp = querymag(2*i, tl, tm, l, r, v);
        if(tmp == -1) tmp = querymag(2*i+1, tm+1, tr, l, r, v);
        return tmp;
    }

    int querymag(int l, int r, int v)
    {
        return querymag(1, 0, n-1, l, r, v);
    }

    int querymageg(int i, int tl, int tr, int l, int r, int v)
    {
        if(r < tl || tr < l) return -1;
        if(tl == tr && t[i] >= v) return tl;
        int tm = (tl + tr) / 2;
        int tmp = querymageg(2*i, tl, tm, l, r, v);
        if(tmp == -1) tmp = querymageg(2*i+1, tm+1, tr, l, r, v);
        return tmp;
    }

    int querymageg(int l, int r, int v)
    {
        return querymageg(1, 0, n-1, l, r, v);
    }
};

void solve()
{
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int &i: a) cin >> i;
    for(int &i: b) cin >> i;

    Segment seg = Segment(n, a);

    vector<int> z(n, -1);
    int mx = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == b[i])
            ans += (i+1)*(n-1);
        else if(a[i] > b[i])
        {
            int j = seg.querymag(0, i-1, a[i]);
            if(j != -1) ans += (i-j+1)*(n-i);
        } else
        {
            int j = seg.querymageg(0, i-1, b[i]);
            if(j != -1) ans += (i-j+1)*(n-1);
        }
    }

    cout << ans << "\n";
}

int main()
{
    int t; cin >> t;
    while(t--) solve();
}
