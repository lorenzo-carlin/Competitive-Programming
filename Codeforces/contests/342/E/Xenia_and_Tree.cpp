#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int INF = 1e9;

struct LCA
{
    int N, LOG;
    vector<vector<int>> up;
    vector<int> depth, par;
    vector<set<int>> adj;

    LCA(vector<set<int>> &adj) : adj(adj)
    {
        N = adj.size();
        LOG = ceil(log2(N))+1;
        up.resize(N, vector<int> (LOG));
        depth.resize(N, 0);
        par.resize(N, -1);
        dfs(0, -1);
        init();
    }

    void dfs(int n, int p)
    {
        for(int i: adj[n])
        {
            if(i == p) continue;
            depth[i] = depth[n]+1;
            par[i] = n;
            dfs(i, n);
        }
    }

    void init()
    {
        for(int j = 0; j < N; ++j)
        {
            up[j][0] = par[j];
        }

        for(int i = 1; i < LOG; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                if(up[j][i-1] == -1) up[j][i] = -1;
                else up[j][i] = up[up[j][i-1]][i-1];
            }
        }
    }

    int lift(int a, int k)
    {
        for(int j = 0; j < LOG; ++j)
        {
            if(a == -1) break;
            if(k & (1<<j)) a = up[a][j];
        }
        return a;
    }

    int lca(int a, int b)
    {
        if(depth[a] > depth[b]) swap(a, b);
        b = lift(b, depth[b]-depth[a]);

        if(a == b) return a;

        for(int j = LOG-1; j >= 0; j--)
        {
            if(up[a][j] != up[b][j])
            {
                a = up[a][j];
                b = up[b][j];
            }
        }

        return up[a][0];
    }

    int dist(int a, int b)
    {
        if(depth[a] > depth[b]) swap(a, b);

        int l = lca(a, b);
        return depth[a]+depth[b]-2*depth[l];
    }

};

struct centroid
{
    vector<set<int>> adj;
    vector<int> par, size;

    centroid(vector<set<int>> &adj) : adj(adj)
    {
        int n = adj.size();
        par.resize(n, -1);
        size.resize(n, 0);
        build(0, -1);
    }

    void build(int u, int p)
    {
        int n = dfs(u, p);
        int cen = findCentroid(u, p, n);
        par[cen] = p;

        vector<int> temp(adj[cen].begin(), adj[cen].end());
        for(int i: temp)
        {
            adj[i].erase(cen);
            build(i, cen);
        }
        adj[cen].clear();
    }

    int dfs(int u, int p)
    {
        size[u] = 1;
        for(int i: adj[u])
        {
            if(i == p) continue;
            size[u] += dfs(i, u);
        }
        return size[u];
    }

    int findCentroid(int u, int p, int n)
    {
        for(int i: adj[u])
        {
            if(i != p && size[i] > n/2)
            {
                return findCentroid(i, u, n);
            }
        }
        return u;
    }

    void print()
    {
        for(int i = 0; i < par.size(); ++i)
        {
            cout << i+1 << ":\t" << par[i]+1 << "\n";
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    vector<set<int>> adj(n);
    for(int i = 0, a, b; i < n-1; ++i)
    {
        cin >> a >> b;
        a--; b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    LCA L = LCA(adj);

    centroid C = centroid(adj);

    vector<int> best(n, INF);

    auto update = [&] (int n) -> void
    {
        int tmp = n;
        while(tmp != -1)
        {
            best[tmp] = min(best[tmp], L.dist(tmp, n));
            tmp = C.par[tmp];
        }

        // for(int el: best) cout << el << " ";
        // cout << "\n";
    };

    auto query = [&] (int n) -> int
    {
        int tmp = n, ans = INF;
        while(tmp != -1)
        {
            ans = min(ans, best[tmp] + L.dist(n, tmp));
            tmp = C.par[tmp];
        }
        return ans;
    };

    update(0);
    // for(int el: best) cout << el << " ";
    // cout << "\n";

    for(int i = 0, t, v; i < q; ++i)
    {
        cin >> t >> v; v--;
        if(t == 1)
        {
            update(v);
        } else
        {
            cout << query(v) << "\n";
        }
    }
}