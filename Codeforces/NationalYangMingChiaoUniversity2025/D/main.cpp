#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

struct HLD {
    vector<int> heavy, head, pos, par, sz, depth;
    vector<vector<int>> g;
    int n, curPos;

    HLD(int _n) : n(_n) {
        g.resize(n);
        heavy.resize(n, -1);
        head.resize(n);
        pos.resize(n);
        par.resize(n, -1);
        sz.resize(n);
        depth.resize(n);
        curPos = 0;
        
    }

    void addEdge(int a, int b) {
        g[a].push_back(b);
        g[b].push_back(a);
    }

    void dfsSize(int node) {
        sz[node] = 1;
        int mxChild = -1;
        for (int x : g[node]) {
            if (x == par[node]) {
                continue;
            }  
            depth[x] = depth[node] + 1;
            par[x] = node;
            dfsSize(x);
            sz[node] += sz[x];
            if (sz[x] > mxChild) {
                mxChild = sz[x];
                heavy[node] = x;
            }
        }
    }

    void decompose(int node, int idChain) {
        pos[node] = curPos++;
        head[node] = idChain;
        if (heavy[node] != -1) {
            decompose(heavy[node], idChain);
        }

        for (int x : g[node]) {
            if (x == heavy[node] or x == par[node]) {
                continue;
            }
            decompose(x, x);
        }
    }

    void build() {
        dfsSize(0);
        decompose(0, 0);
    }

    pair<int, int> ranges[256];
    int getRanges(int u, int v) {
        int i = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                swap(u, v);
            }

            ranges[i++] = {pos[head[v]], pos[v]};
            v = par[head[v]];
        }

        if (depth[u] > depth[v]) {
            swap(u, v);
        }
        ranges[i++] = {pos[u], pos[v]};
        return i;
    }
};

#include <array>

struct Node {
    array<int, 3> cnt;

    Node() {
        cnt = {1, 0, 0};
    }

    Node(int v) {
        cnt = {v, v, v};
    }

    Node& operator += (const Node &oth) {
        for (int i = 0; i < 3; ++i) {
            cnt[i] += oth.cnt[i];
        }
        return *this;
    }

    void apply(int x) {
        if (x == 0) {
            assert(false);
        }

        if (abs(x) == 2) {
            assert(cnt[1] == 0);
            if (x == 2) {
                cnt[2] = cnt[0];
                cnt[0] = 0;
            } else {
                cnt[0] = cnt[2];
                cnt[2] = 0;
            }
        } else {
            if (x == -1) { // decrease
                assert(cnt[0] == 0);
                for (int i = 0; i < 2; ++i) {
                    cnt[i] = cnt[i + 1];
                }
                cnt[2] = 0;
            } else {
                assert(cnt[2] == 0);
                for (int i = 2; i >= 1; --i) {
                    cnt[i] = cnt[i - 1];
                }
                cnt[0] = 0;
            }
        }
    }
};  

Node operator + (Node a, const Node &b) {
    a += b;
    return a;
}

struct LazySeg {
    vector<Node> seg;
    int n;
    vector<int> tags;

    LazySeg(int _n) : n(_n) {
        tags.resize(n << 2);
        seg.resize(n << 2);
        auto build = [&](auto &&self, int l, int r, int i) -> void {
            if (l == r) {
                return;
            } else {
                int mid = (l + r) / 2;
                self(self, l, mid, i * 2);
                self(self, mid + 1, r, i * 2 + 1);
                pull(i);
            }
        };

        build(build, 0, n - 1, 1);
    }

    void push(int i, int v) {
        tags[i * 2] += v;
        tags[i * 2 + 1] += v;
    }

    void pull(int i) {
        seg[i] = seg[i * 2] + seg[i * 2 + 1];
    }

    void isLazy(int i, bool has) {
        if (tags[i] != 0) {
            seg[i].apply(tags[i]);
            if (has) {
                push(i, tags[i]);
            }
            tags[i] = 0;
        }
    }

    void rangeAdd(int sq, int eq, int v, int l, int r, int i) {
        bool has = l != r;
        if (l > eq or r < sq) {
            return;
        }

        if (l >= sq and r <= eq) {
            tags[i] += v;
            isLazy(i, has);
            return;
        }

        int mid = (l + r) / 2;
        rangeAdd(sq, eq, v, l, mid, i * 2);
        rangeAdd(sq, eq, v, mid + 1, r, i * 2 + 1);
        pull(i);
    }

    void rangeAdd(int l, int r, int v) {
        rangeAdd(l, r, v, 0, n - 1, 1);
    }

    Node getRange(int sq, int eq, int l, int r, int i) {
        isLazy(i, l != r);

        if (l > eq || r < sq) {
            return Node(1);
        }

        if (l >= sq and r <= eq) {
            return seg[i];
        }

        int mid = (l + r) / 2;
        return getRange(sq, eq, l, mid, i * 2) + 
               getRange(sq, eq, mid + 1, r, i * 2 + 1);
    }

    int getRange(int l, int r) {
        Node nd = getRange(l, r, 0, n - 1, 1);
        for (int i = 0; i < 3; ++i) {
            cerr << "I " << i << " --> " << nd.cnt[i] << endl;
        }
        return nd.cnt[1] + nd.cnt[2];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    
    HLD hld(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        hld.addEdge(u, v);
    }

    hld.build();

    LazySeg seg(n);

    auto update = [&](int u, int v, int k) {
        int cnt = hld.getRanges(u, v);
        for (int i = 0; i < cnt; ++i) {
            auto [l, r] = hld.ranges[i];
            seg.rangeAdd(l, r, k);
        }
    };

    auto add = [&](int u, int v) {
        update(u, v, 1);
    };

    auto remove = [&](int u, int v) {
        update(u, v, -1);
    };

    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a, --b, --c, --d;
        
        add(a, b);
        add(c, d);

        int ans = seg.getRange(0, n - 1);
        cout << ans << "\n";

        remove(a, b);
        remove(c, d);

        ans = seg.getRange(0, n - 1);
        cout << "BOH " << ans << "\n";

    }

    return 0;
}