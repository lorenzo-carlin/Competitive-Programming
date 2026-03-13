#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for(int &i: v) cin >> i;
    vector<vector<int>> adj(n);
    for(int i = 0, a, b; i < n-1; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int tmr = 0;
    vector<int> order, tin(n), tout(n);
    auto dfs = [&] (auto dfs, int v, int p) -> void
    {
        order.push_back(v);
        tin[v] = tmr++;
        for(int u: adj[v])
        {
            if(u == p) continue;
            dfs(dfs, u, v);
        }
        tout[v] = tmr;
    };
    dfs(dfs, 0, -1);

    Segment seg = Segment(n);
    // Inizializzo il segment
    for(int i = 0; i < n; i++) seg.update(i, v[order[i]]);

    // Operazioni del tipo 1: cambio il valore del nodo j a x
    seg.update(tin[j], x);

    // Operazione del tipo 2: somma dei valori sul subtree del nodo j
    cout << seg.query(tin[j], tout[j]-1) << "\n";
}
