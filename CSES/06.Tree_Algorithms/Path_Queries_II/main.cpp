#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct Segment {
    int n;
    vector<int> t;

    Segment() {}
	Segment(vector<int> v) : n(v.size())
	{
		t.resize(2*n);
		for(int i = 0; i < n; ++i) t[i+n] = v[i];
		for(int i = n-1; i > 0; --i) t[i] = max(t[2*i], t[2*i+1]);
	}

	void update(int p, int v)
	{
		for(t[p += n] = v; p > 1; p >>= 1)
		{
			t[p >> 1] = max(t[p], t[p^1]);
		}
	}

	int query(int l, int r)
	{
		int ans = 0;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1)
		{
			if(l & 1) ans = max(ans, t[l++]);
			if(r & 1) ans = max(ans, t[--r]);
		}
		return ans;
	}
};

struct HLD {
    int n, timer = 0;
    vector<int> par, pos, size, depth, head;
    vector<vector<int>> adj;
    Segment seg;

    HLD(const vector<vector<int>>& _adj, const vector<int>& val) {
        n = _adj.size();
        adj = _adj;

        par.assign(n, -1);
        pos.assign(n, -1);
        size.assign(n, 1);
        head.assign(n, 0);
        depth.assign(n, 0);

        dfs(0, -1);
        decompose(0, 0);

        vector<int> tmp(n, 0);
        seg = Segment(tmp);
        for (int i = 0; i < n; ++i) seg.update(pos[i], val[i]);
    }

    void dfs(int node, int p) {
        for (int v : adj[node]) {
            if (v == p) continue;
            par[v] = node;
            depth[v] = depth[node] + 1;
            dfs(v, node);
            size[node] += size[v];
        }
		sort(begin(adj[node]), end(adj[node]), [&](int x, int y)
		{
			return size[x] > size[y];
		});
    }

    void decompose(int node, int p) {
        pos[node] = timer++;
        bool heavy_found = false;

        for (int v : adj[node]) {
            if (p == v) continue;
            if (!heavy_found) {
                heavy_found = true;
                head[v] = head[node];
            } else {
                head[v] = v;
            }
            decompose(v, node);
        }
    }

    void update(int p, int v) {
        seg.update(pos[p], v);
    }

    int query(int a, int b) {
        int ans = 0;

        while (head[a] != head[b]) {
            if (depth[head[a]] > depth[head[b]]) swap(a, b);
            ans = max(ans, seg.query(pos[head[b]], pos[b]+1));
            b = par[head[b]];
        }

        if (depth[a] > depth[b]) swap(a, b);
        ans = max(ans, seg.query(pos[a], pos[b]+1));

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    scanf("%d %d", &n, &q);
    vector<vector<int>> adj(n);
    vector<int> val(n);
    for (int& i : val) scanf("%d", &i);
    for (int i = 0, a, b; i < n - 1; ++i) {
        scanf("%d %d", &a, &b);
        --a; --b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    HLD h = HLD(adj, val);

    for (int i = 0, t, x, y; i < q; ++i) {
        scanf("%d %d %d", &t, &x, &y);
        if (t == 1) {
            --x;
            h.update(x, y);
        } else {
            --x; --y;
            printf("%d ", h.query(x, y));
        }
    }
    printf("\n");

    return 0;
}

