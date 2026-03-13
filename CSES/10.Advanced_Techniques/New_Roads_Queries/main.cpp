#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
constexpr int LOG = 20;
constexpr int MAXN = 2e5+5;
vector<vector<int>> up(MAXN, vector<int> (LOG, -1));
vector<vector<int>> mx(MAXN, vector<int> (LOG, -1));
 
struct DSU {
    int n;
    vector<int> par;
 
    DSU() {}
    DSU(int _n) {
        n = _n;
        par.resize(n);
        iota(begin(par), end(par), 0);
    }
 
    int find(int a) {
        if(par[a] == a) return a;
        else return par[a] = find(par[a]);
    }
 
    bool merge(int a, int b) {
        int A = find(a);
        int B = find(b);
 
        if(A == B) return false;
        par[A] = B;
        return true;
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    // lettura archi in input
    int n, m, q; cin >> n >> m >> q;
    vector<array<int,3>> edges(m);
    for(int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        a--; b--;
        edges[i] = {i+1, a, b}; // {day, nodo_a, nodo_b}
    }
 
    // creo l'MST
    vector<vector<pair<int,int>>> adj(n); // {nodo_b, day}
    vector<int> depth(n, 0);
 
    DSU dsu = DSU(n);
    for(int i = 0; i < m; ++i) {
        if(dsu.merge(edges[i][1], edges[i][2])) {
            adj[edges[i][1]].push_back({edges[i][2], edges[i][0]});
            adj[edges[i][2]].push_back({edges[i][1], edges[i][0]});
        }
    }
 
    auto dfs = [&] (auto dfs, int v, int p) -> void {
        for(auto [u, day]: adj[v]) {
            if(u == p) continue;
            depth[u] = depth[v]+1;
            up[u][0] = v;
            mx[u][0] = day;
            dfs(dfs, u, v);
        }
    };
 
    for(int i = 0; i < n; ++i) {
        if(up[i][0] == -1) dfs(dfs, i, -1);
    }
 
    for(int j = 1; j < LOG; ++j) {
        for(int i = 0; i < n; ++i) {
            if(up[i][j-1] == -1) up[i][j] = -1;
            else up[i][j] = up[up[i][j-1]][j-1];
 
            int mx1 = mx[i][j-1];
            int mx2 = (up[i][j-1] == -1) ? (-1) : (mx[up[i][j-1]][j-1]);
            mx[i][j] = max(mx1, mx2);
        }
    }
 
    auto lift = [&] (int a, int k) -> int {
        for(int j = LOG-1; j >= 0; j--) {
            if(a == -1) break;
            if(k & (1 << j)) {
                a = up[a][j];
            }
        }
        return a;
    };
 
    auto LCA = [&] (int a, int b) -> int {
        if(depth[a] > depth[b]) {
            swap(a, b);
        }
        int difH = depth[b]-depth[a];
        b = lift(b, difH);
 
        if(a == b) return a;
        for(int j = LOG-1; j >= 0; j--) {
            if(up[a][j] != up[b][j]) {
                a = up[a][j];
                b = up[b][j];
            }
        }
 
        return up[a][0];
    };
 
    auto maxonpath = [&] (int a, int k) -> int {
        int mxx = 0;
        for(int j = LOG-1; j >= 0; j--) {
            if(k & (1 << j)) {
                mxx = max(mxx, mx[a][j]);
                a = up[a][j];
            }
        }
        return mxx;
    };
 
    // se le due strade non sono collegate hanno find(a) != find(b) e quella query non la considero neanche
    for(int i = 0, a, b; i < q; ++i) {
        cin >> a >> b;
        a--; b--;
        if(dsu.find(a) != dsu.find(b)) {
            cout << -1 << "\n";
        } else {
            int l = LCA(a, b);
            int difHa = depth[a] - depth[l];
            int difHb = depth[b] - depth[l];
            cout << max(maxonpath(a, difHa), maxonpath(b, difHb)) << "\n";
        }
    }
}
