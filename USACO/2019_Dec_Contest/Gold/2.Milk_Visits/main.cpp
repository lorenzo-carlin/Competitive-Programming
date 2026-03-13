#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    int n, m; cin >> n >> m;
    vector<int> t(n);
    for(int &i: t) cin >> i;
    vector<vector<int>> adj(n);
    for(int i = 0, a, b; i < n-1; i++)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int tmr = 0;
    vector<int> preorder, tin(n), tout(n), height, order;
    vector<vector<int>> open(n+1), close(n+1);
    auto dfs = [&] (auto dfs, int v, int p, int h) -> void
    {
        preorder.push_back(v);
        order.push_back(v);
        height.push_back(h);
        tin[v] = tmr++;
        open[t[v]].push_back(tin[v]);
        for(int u: adj[v])
        {
            if(u == p) continue;
            dfs(dfs, u, v, h+1);
            order.push_back(v);
            height.push_back(h);
        }
        tout[v] = tmr++;
        close[t[v]].push_back(tout[v]);
        preorder.push_back(v);
        order.push_back(v);
        height.push_back(h);
    };
    
    dfs(dfs, 0, -1, 0);

    /*
    cout << "tin: ";
    for(int el: tin) cout << el << " ";
    cout << "\n";
    cout << "tout: ";
    for(int el: tout) cout << el << " ";
    cout << "\n";
    */

    // Funzione per trovare LCA
    int sz = order.size();
    vector<int> log(sz+1, 0);
    for(int i = 2; i <= sz; i++)
        log[i] = log[i/2]+1;

    /*
    cout << "preorder: ";
    for(int el: preorder) cout << el << " ";
    cout << "\n";
    cout << "height: ";
    for(int el: height) cout << el << " ";
    cout << "\n";
    cout << "order: ";
    for(int el: order) cout << el << " ";
    cout << "\n";
    */

    int L = log[sz];
    vector<vector<pair<int,int>>> st(L+1, vector<pair<int,int>> (sz));
    for(int i = 0; i < sz; i++)
        st[0][i] = {height[i], i};
    for(int i = 1; i <= L; i++)
        for(int j = 0; j + (1 << i) - 1 < sz; j++)
            st[i][j] = min(st[i-1][j], st[i-1][j+(1<<(i-1))]);

    auto LCA = [&] (int a, int b) -> int
    {
        int s = min(tin[a], tin[b]), f = max(tin[a], tin[b]);
        int k = log[f-s+1];
        auto mn = min(st[k][s], st[k][f-(1<<k)+1]);
        int x = mn.second;
        int lca = order[x];
        return lca;
    };

    for(int i = 0, a, b, c; i < m; i++)
    {
        cin >> a >> b >> c;
        a--; b--;
        int lca = LCA(a, b);

        int nr_attivi = upper_bound(begin(open[c]), end(open[c]), tin[a])-lower_bound(begin(open[c]), end(open[c]), tin[lca]);
        int nr_spenti = upper_bound(begin(close[c]), end(close[c]), tin[a])-lower_bound(begin(close[c]), end(close[c]), tin[lca]);
        if(nr_attivi > nr_spenti)
        {
            cout << 1;
            continue;
        }
        nr_attivi = upper_bound(begin(open[c]), end(open[c]), tin[b])-lower_bound(begin(open[c]), end(open[c]), tin[lca]);
        nr_spenti = upper_bound(begin(close[c]), end(close[c]), tin[b])-lower_bound(begin(close[c]), end(close[c]), tin[lca]);
        if(nr_attivi > nr_spenti) cout << 1;
        else cout << 0;
    }

    cout << "\n";
}
