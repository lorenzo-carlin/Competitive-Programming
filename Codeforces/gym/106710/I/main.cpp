#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    vector<int> par, sz;

    DSU(int n) : par(n), sz(n, 1) {
        iota(begin(par), end(par), 0);
    }

    int find(int x) {
        if(par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    void unite(int a, int b) {
        int A = find(a);
        int B = find(b);

        if(A == B) {
            return;
        }

        if(sz[A] < sz[B]) {
            swap(A, B);
        }

        par[B] = A;
        sz[A] += sz[B];
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<ll> a(n);
    for(ll &i: a) cin >> i;

    DSU dsu(n);
    vector<pair<int,int>> edges;
    for(int i = 0; i < n-1; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        x--; y--;
        if(c == '=') {
            dsu.unite(x, y);
        } else if(c == '>') {
            edges.push_back({x, y});
        } else if(c == '<') {
            edges.push_back({y, x});
        }
    }

    vector<int> root(n);
    for(int i = 0; i < n; i++) {
        root[i] = dsu.find(i);
    }

    vector<vector<int>> adj(n);
    for(auto [u, v]: edges) {
        int U = root[u];
        int V = root[v];

        if(U != V) {
            adj[U].push_back(V);
        }
    }

    vector<ll> w(n, -1);
    
    auto dfs = [&] (auto dfs, int v) -> ll {
        if(w[v] != -1) {
            return w[v];
        }

        ll mx = 0;
        for(int u: adj[v]) {
            mx = max(mx, dfs(dfs, u));
        }

        return w[v] = (ll) mx+1;
    };

    for(int i = 0; i < n; i++) {
        dfs(dfs, root[i]);
    }

    ll tot = 0;
    for(int i = 0; i < n; i++) {
        tot += a[i]*w[root[i]];
    }

    cout << tot << "\n";
    for(int i = 0; i < n; i++) {
        cout << w[root[i]] << " ";
    }
    cout << "\n";
}