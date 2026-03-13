#include <bits/stdc++.h>
using namespace std;

int cont = 0, n;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> st, fn;

int dfs(int node)
{
    st[node] = cont++;
    vis[node] = true;
    int tmp = cont;
    for(int i: adj[node])
    {
        if(!vis[i]) tmp = dfs(i);
    }
    return fn[node] = tmp;
}

struct Segment
{
    vector<pair<bool,int>> t;

    Segment(int _n)
    {
        for(n = 1; n < _n; n <<= 1);
        t.resize(2*n, {false, -1});
    }

    void update(int i, int tl, int tr, int l, int r, bool v, int tmr)
    {
        if(r < tl || tr < l) return;
        if(l <= tl && tr <= r)
        {
            t[i] = {v, tmr};
            return;
        }
        if(tl == tr)
        {
            t[i] = {v, tmr};
            return;
        }
        int tm = (tl + tr) / 2;
        update(2*i, tl, tm, l, r, v, tmr);
        update(2*i+1, tm+1, tr, l, r, v, tmr);
    }
    
    void update(int l, int r, int v, int tmr)
    {
        update(1, 0, n-1, l, r, v, tmr);
    }

    bool query(int i, int tl, int tr, int p)
    {
        int tmp = -1;
        bool ans = false;
        for(p += n; p > 0; p >>= 1)
        {
            if(t[p].second > tmp)
            {
                ans = t[p].first;
                tmp = t[p].second;
            }
        }
        return ans;
    }

    bool query(int p)
    {
        return query(1, 0, n-1, p);
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d, p, e; cin >> d >> p >> e;

    int sz = d+p;
    int buf; cin >> buf;
    adj.resize(sz), vis.resize(sz, false), st.resize(sz), fn.resize(sz);

    for(int i = 1; i < sz; ++i)
    {
        int a; cin >> a;
        adj[a].push_back(i);
    }
    fn[0] = dfs(0);

    Segment seg = Segment(sz);

    for(int i = 0; i < e; ++i)
    {
        int a, b; cin >> a >> b;
        if(a == 0) seg.update(st[b], fn[b]-1, false, i);
        if(a == 1) seg.update(st[b], fn[b]-1, true, i);
        if(a == 2)
        {
            bool res = seg.query(st[b]);
            if(res) cout << "1\n";
            else cout << "0\n";
        }
    }
}