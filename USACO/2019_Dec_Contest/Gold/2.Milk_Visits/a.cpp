#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<int> t(n);
    vector<vector<int>> adj(n), queries(n);
    vector<array<int,4>> q(m);
    vector<bool> ans(m, false);
    for(int &i: t) cin >> i;
    for(int i = 0, a, b; i < n-1; i++)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0, a, b, c; i < m; i++)
    {
        cin >> a >> b >> c; a--; b--;
        q[i] = {a, b, c, i};
        queries[a].push_back(i);
        queries[b].push_back(i);
    }

    int tmr = 0;
    vector<int> tin(n), tout(n);
    auto dfs1 = [&] (auto dfs1, int v, int p) -> void
    {
        tin[v] = tmr++;
        for(int u: adj[v])
        {
            if(u == p) continue;
            dfs1(dfs1, u, v);
        }
        tout[v] = tmr++;
    };
    dfs1(dfs1, 0, -1);

    auto is_ancestor = [&] (int a, int b) -> bool // a è antenato di b?
    {
        if(tin[a] <= tin[b] && tout[a] >= tout[b]) return true;
        return false;
    };

    int idx = 0;
    vector<int> s(n, -1);
    vector<stack<pair<int,int>>> types(n+1);
    auto dfs2 = [&] (auto dfs2, int v, int p, int h) -> void
    {
        s[idx++] = v;
        types[t[v]].push({v, h});

        // risolvo le query
        for(int qq: queries[v])
        {
            int x = (q[qq][0] == v) ? (q[qq][1]) : (q[qq][0]);
            int t = q[qq][2];
            if(types[t].empty()) continue;
            int last = types[t].top().first;
            int hlast = types[t].top().second;
            if(!is_ancestor(last, x)) ans[q[qq][3]] = true;
            else if(last != v)
            {
                int nxt = s[hlast+1];
                if(!is_ancestor(nxt, x)) ans[q[qq][3]] = true;
            }
        }

        for(int u: adj[v])
        {
            if(u == p) continue;
            dfs2(dfs2, u, v, h+1);
        }

        types[t[v]].pop();
        idx--;
    };
    dfs2(dfs2, 0, -1, 0);

    for(int i = 0; i < m; i++)
    {
        if(ans[i]) cout << 1;
        else cout << 0;
    }

    cout << "\n";
}
