#include <bits/stdc++.h>
using namespace std;
using ll = long long;


signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<vector<pair<ll,ll>>> adj(n);
    for(ll i = 0; i < n-1; i++) {
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    ll m; cin >> m;
    set<ll> ext_bridges;
    vector<ll> deg_bridges(n, 0);
    vector<pair<ll,ll>> bridges(m);
    for(ll i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        a--; b--;
        bridges[i] = {a, b};
        ext_bridges.insert(a);
        ext_bridges.insert(b);
        deg_bridges[a]++;
        deg_bridges[b]++;
    }

    // rimuovere le foglie non utili
    queue<ll> q;
    for(ll i = 0; i < n; i++) {
        if(adj[i].size() == 1) {
            q.push(i);
        }
    }
    vector<bool> removed(n, false);
    while(!q.empty()) {
        ll v = q.front();
        q.pop();
        int vicini = 0;
        for(auto [u, w]: adj[v]) {
            if(!removed[u]) {
                vicini++;
            }
        }
        if(vicini > 1) {
            continue;
        }
        if(ext_bridges.count(v) == 0) {
            removed[v] = true;
            for(auto [u, w]: adj[v]) {
                if(removed[u]) {
                    continue;
                }
                q.push(u);
            }
        }
    }

    vector<vector<pair<ll,ll>>> G(n);
    for(ll i = 0; i < n; i++) {
        if(removed[i]) {
            continue;
        }
        for(auto [u, w]: adj[i]) {
            if(removed[u]) {
                continue;
            }
            G[i].push_back({u, w});
        }
    }

    auto dfs = [&] (auto dfs, ll v, ll p, ll w) -> ll {
        ll tot = 0;

        for(auto[u, _]: G[v]) {
            if(u == p) {
                continue;
            }
            tot += dfs(dfs, u, v, _);
        }

        if(deg_bridges[v] & 1) {
            tot += w;
            deg_bridges[v]++;
            deg_bridges[p]++;
        }

        return tot;
    };

    for(int i = 0; i < n; i++) {
        if(!removed[i]) {
            cout << dfs(dfs, i, -1, 0) << "\n";
            return 0;
        }
    }
}