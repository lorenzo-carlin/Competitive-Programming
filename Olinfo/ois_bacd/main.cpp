#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll mod = 1e9+7;

struct Segment
{
    int n;
    vector<ll> t;

    Segment() {}
    Segment(int _n)
    {
        for(n = 1; n < _n; n<<=1);
        t.resize(2*n, 0);
    }

    void update(int i, int tl, int tr, int p, int v)
    {
        if(p < tl || p > tr) return;
        if(tl == tr && tl && p) t[i] = v;
        else
        {
            int tm = (tl + tr) / 2;
            update(2*i, tl, tm, p, v);
            update(2*i+1, tm+1, tr, p, v);
            t[i] = t[2*i] + t[2*i+1];
        }
    }

    void update(int p, int v)
    {
        update(1, 0, n-1, p, v);
    }

    ll query(int i, int tl, int tr, int l, int r)
    {
        if(r < tl || tr < l) return 0;
        if(l <= tl && tr <= r) return t[i];
        int tm = (tl + tr) / 2;
        return query(2*i, tl, tm, l, r) + query(2*i+1, tm+1, tr, l, r);
    }

    ll query(int l, int r)
    {
        return query(1, 0, n-1, l, r);
    }

    void clear()
    {
        for(int i = 0; i < 2*n; i++)
            t[i] = 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> v(n);
    for(int &i: v) cin >> i;

    Segment seg = Segment(n+1);
    vector<ll> dp2(n, 0);
    for(int i = n-1; i >= 0; i--)
    {
        dp2[i] = seg.query(v[i]+1, n);
        seg.update(v[i], 1);
    }

    cout << "dp2:\n";
    for(int el: dp2) cout << el << " ";
    cout << "\n";

    seg.clear();

    vector<ll> dp3(n, 0);
    for(int i = n-1; i >= 0; i--)
    {
        dp3[i] = seg.query(v[i]+1, n);
        seg.update(v[i], dp2[i]);
    }

    cout << "dp3:\n";
    for(int el: dp3) cout << el << " ";
    cout << "\n";

    stack<int> s;
    ll sum = 0;
    for(int i = n-1; i >= 0; i--)
    {
        int x = -1;
        while(!s.empty() && v[s.top()] < v[i])
            s.pop();
        if(!s.empty())
            x = s.top();
        s.push(i);
        sum += dp3[i];
        sum %= mod;
        if(x != -1) sum += (mod - dp2[x]);
        sum %= mod;
    }

    cout << sum << "\n";
}
