#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;

constexpr int LOG = 20;
constexpr int MAXN = 1e5+5;
int up[MAXN][LOG];
int mx[MAXN][LOG];
vector<int> par, dep;
vector<array<int,3>> edges, order;
vector<vector<pair<int,int>>> adj;
map<pair<int,int>,int> weights;

void dfs(int n, int p)
{
    for(auto [v, w]: adj[n])
    {
        if(v == p) continue;
        par[v] = n;
        dep[v] = dep[n]+1;
        dfs(v, n);
    }
}

int lift(int a, int k)
{
    for(int i = 0; i < LOG; ++i)
    {
        if(a == -1) break;
        if(k & (1 << i))
        {
            a = up[a][i];
        }
    }
    return a;
}

int lca(int a, int b)
{
    if(dep[a] > dep[b]) swap(a, b);
    b = lift(b, dep[b]-dep[a]);

	if(a == b) return a;
    for(int i = LOG-1; i >= 0; i--)
    {
        if(up[a][i] != up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int mxx(int a, int b)
{
    int l = lca(a, b);

    int dif_a = dep[a] - dep[l];
    int mx1 = 0;
    for(int i = 0; i < LOG; ++i)
    {
        if(dif_a & (1 << i))
        {
            mx1 = max(mx1, mx[a][i]);
            a = up[a][i];
        }
    }

    int dif_b = dep[b] - dep[l];
    int mx2 = 0;
    for(int i = 0; i < LOG; ++i)
    {
        if(dif_b & (1 << i))
        {
            mx2 = max(mx2, mx[b][i]);
            b = up[b][i];
        }
    }

    return max(mx1, mx2);
}

struct DSU
{
    int n;
    vector<int> p;

    DSU(int _n)
    {
        n = _n;
        p.resize(n);
        iota(begin(p), end(p), 0);
    }

    int find(int a)
    {
        return (p[a] == a) ? (a) : (p[a] = find(p[a]));
    }

    void merge(int a, int b)
    {
        int A = find(a);
        int B = find(b);
        if(A != B) p[B] = A;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s; cin >> n >> s;
    edges.resize(n); order.resize(n); adj.resize(s);
    par.resize(s, -1); dep.resize(s, 0);
    for(int i = 0; i < n; ++i)
    {
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
        order[i][1] = edges[i][1];
        order[i][2] = edges[i][2];
        order[i][0] = edges[i][0];
    }

    DSU dsu = DSU(s);

    sort(begin(order), end(order));
    ll tot = 0;
    for(int i = 0; i < n; ++i)
    {
        if(dsu.find(order[i][1]) != dsu.find(order[i][2]))
        {
            dsu.merge(order[i][1], order[i][2]);
            adj[order[i][1]].push_back({order[i][2], order[i][0]});
            adj[order[i][2]].push_back({order[i][1], order[i][0]});
			weights[{order[i][1], order[i][2]}] = order[i][0];
			weights[{order[i][2], order[i][1]}] = order[i][0];
            tot += (ll) order[i][0];
        }
    }

	dfs(0, -1);

    for(int i = 0; i < s; ++i)
    {
        up[i][0] = par[i];
    }
    for(int j = 1; j < LOG; ++j)
    {
        for(int i = 0; i < s; ++i)
        {
            if(up[i][j-1] == -1) up[i][j] = -1;
            else up[i][j] = up[up[i][j-1]][j-1];
        }
    }

	for(int i = 0; i < s; ++i)
	{
		if(par[i] == -1) mx[i][0] = 0;
		else mx[i][0] = weights[{i, par[i]}];
	}
	for(int j = 1; j < LOG; ++j)
	{
		for(int i = 0; i < s; ++i)
		{
			int mx1 = mx[i][j-1];
			int mx2 = (up[i][j-1] == -1) ? (0) : (mx[up[i][j-1]][j-1]);
			mx[i][j] = max(mx1, mx2);
		}
	}

    for(auto el: edges)
    {
        ll ans = tot + el[0] - mxx(el[1], el[2]);
        cout << ans << "\n";
    }
}
