#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

using i64 = long long;

// https://github.com/the-tourist/algo/blob/master/data/dsu.cpp
constexpr int N = 5005;
int dsu[N];

struct DSU {
    DSU(int n) {
        fill(dsu, dsu + n, -1);
    }

    int find(int x) {
        return dsu[x] < 0 ? x : (dsu[x] = find(dsu[x]));
    }

    bool sameSet(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) {
            return false;
        }

        if (dsu[x] > dsu[y]) {
            swap(x, y);
        }

        dsu[x] += dsu[y];
        dsu[y] = x;
        
        return true;
    }
};

#include <map>

constexpr int inf = 1E9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);

    vector<int> h(n);
    auto get = [&](int i, int j) {
        return max(h[i], h[j]);
    };

    auto get2 = [&](int i, int j) {
        return min(h[i], h[j]);
    };

    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        int w = get(u, v);
        edges[i] = {w, u, v};
        // cout << "Edges " << u << " " << v << " --> " << w << endl;
    }

    sort(edges.begin(), edges.end());
    auto p = h;
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());

    map<int, int> firstOcc;
    for (int i = 0; i < m; ++i) {
        auto [w, u, v] = edges[i];
        // cout << w << " " << v << " " << u << " idx " << i << endl;
        if (!firstOcc.count(w)) {
            firstOcc[w] = i;
        }
    }

    int ans = inf;
    vector<bool> bad(m);

    for (int i = 0; i < int(p.size()); ++i) {
        DSU dsu(n);
        // cout << "w " << p[i] << endl;
        for (int j = firstOcc[p[i]]; j < m; ++j) {
            auto &[w, u, v] = edges[j];
            // cout << "edge " << u << " " << v << " --> " << get2(u, v) << " to beat " << p[i] << endl; 
            if (get2(u, v) < p[i]) {
                continue;
            }
            // cout << "Unite " << u << " " << v << endl;
            dsu.merge(u, v);
            if (dsu.sameSet(0, 1)) {
                ans = min(ans, w - p[i]);
                break;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}