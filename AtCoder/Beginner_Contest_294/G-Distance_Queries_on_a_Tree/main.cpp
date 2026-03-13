#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Segment
{
    int n;
    vector<ll> t;

    Segment() {}
    Segment(vector<ll> a)
    {
        int _n = a.size();
        for(n = 1; n < _n; n <<= 1);
        t.resize(n);
        for(int i = 0; i < _n; i++) t[i+n] = a[i];
        for(int i = n-1; i > 0; i--) t[i] = t[2*i]+t[2*i+1];
    }

    void update(int i, int tl, int tr, int p, int v)
    {
        if(p < tl || tr < p) return;
        if(tl == tr && p == tl) t[i] = v;
        else
        {
            int tm = (tl + tr) / 2;
            update(2*i, tl, tm, p, v);
            update(2*i+1, tm+1, tr, p, v);
            t[i] = t[2*i]+t[2*i+1];
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
    };

    ll query(int l, int r)
    {
        return query(1, 0, n-1, l, r);
    }

    void print()
    {
        cout << "seg: ";
        for(int i = n; i < 2*n; i++)
            cout << t[i] << " ";
        cout << "\n";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<vector<array<int,3>>> adj(n);
    vector<pair<int,int>> edges(n-1);
    for(int i = 0, a, b, c; i < n-1; i++)
    {
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c, i});
        adj[b].push_back({a, c, i});
        edges[i] = {a, b};
    }

    int tmr = 0;
    vector<int> preorder, tin(n), tout(n), order, first(n, -1), height(n, -1);
    auto dfs1 = [&] (auto dfs, int v, int p, int h) -> void
    {
        height[v] = h;
        preorder.push_back(v);
        if(first[v] == -1) first[v] = order.size();
        order.push_back(v);
        tin[v] = tmr++;

        for(auto [u, w, idx]: adj[v])
        {
            if(u == p) continue;
            dfs(dfs, u, v, h+1);
            order.push_back(v);
        }

        preorder.push_back(v);
        tout[v] = tmr++;
    };
    dfs1(dfs1, 0, -1, 0);
/*
    cout << "tin: ";
    for(int el: tin) cout << el << " ";
    cout << "\n";
    cout << "tout: ";
    for(int el: tout) cout << el << " ";
    cout << "\n";
*/
    vector<ll> vec(2*n);
    auto dfs2 = [&] (auto dfs2, int v, int p) -> void
    {
        for(auto [u, w, idx]: adj[v])
        {
            if(u == p) continue;
            vec[tin[u]] = w;
            vec[tout[u]] = -w;
            if(edges[idx].first == u) swap(edges[idx].first, edges[idx].second);
            dfs2(dfs2, u, v);
        }
    };
    dfs2(dfs2, 0, -1);

    int sz = order.size();
    vector<int> log(sz+1, 0);
    for(int i = 2; i <= sz; i++)
        log[i] = log[i/2]+1;
    int k = log[sz];
    vector<vector<pair<int,int>>> st(k+1, vector<pair<int,int>> (sz));
    for(int i = 0; i < sz; i++)
        st[0][i] = {height[order[i]], order[i]};
    for(int i = 1; i <= k; i++)
        for(int j = 0; j < sz; j++)
            st[i][j] = min(st[i-1][j], st[i-1][j+(1<<(i-1))]);

    auto LCA = [&] (int a, int b) -> int
    {
        int start = min(first[a], first[b]);
        int finish = max(first[a], first[b]);
        int L = log[finish-start+1];
        auto ans = min(st[L][start], st[L][finish-(1<<L)+1]);
        return ans.second;
    };

    Segment seg = Segment(vec);
/*  
    cout << "vec: ";
    for(int el: vec) cout << el << " ";
    cout << "\n";
*/
    int q; cin >> q;
    while(q--)
    {
        int type; cin >> type;
        if(type == 1)
        {
            int i, w; cin >> i >> w; i--;
            seg.update(tin[edges[i].second], w);
            seg.update(tout[edges[i].second], -w);
        } else
        {
            int u, v; cin >> u >> v;
            u--; v--;
            int lca = LCA(u, v);
            // seg.print();
            // cout << "u: " << u << ", v: " << v << ", lca: " << lca << "\n";
            ll ans = seg.query(tin[lca], tin[u]) + seg.query(tin[lca], tin[v]) - 2*seg.query(tin[lca], tin[lca]);
            cout << ans << "\n";
        }
    }
}
