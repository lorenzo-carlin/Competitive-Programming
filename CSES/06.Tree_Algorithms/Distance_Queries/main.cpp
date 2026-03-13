#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int LOG = 18;
constexpr int MAXN = 2e5 + 5;
int up[MAXN][LOG];
vector<int> par(MAXN), dep(MAXN);
vector<vector<int>> adj(MAXN);
vector<int> tsort;

void dfs(int n, int p)
{
    tsort.push_back(n);
    for(int v: adj[n])
    {
        if(v == p) continue;
        dep[v] = dep[n]+1;
        par[v] = n;
        dfs(v, n);
    }
}

int lift(int a, int k)
{
    for(int i = 0; i < LOG; ++i)
    {
        if(a == -1) break;
        if(k & (1 << i)) a = up[a][i];
    }
    return a;
}

int lca(int a, int b)
{
    if(dep[a] > dep[b]) swap(a, b);
    b = lift(b, (dep[b]-dep[a]));
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

int dist(int a, int b)
{
    int l = lca(a, b);
    int ans = dep[a] + dep[b] - 2*dep[l];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    for(int i = 0, a, b; i < n-1; ++i)
    {
        cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    par[0] = -1;
    dep[0] = 0;
    dfs(0, -1);

    for(int i = 0; i < n; ++i)
    {
        up[tsort[i]][0] = par[tsort[i]];
        for(int j = 1; j < LOG; ++j)
        {
            if(up[tsort[i]][j-1] == -1) up[tsort[i]][j] = -1;
            else up[tsort[i]][j] = up[up[tsort[i]][j-1]][j-1];
        }
    }

    for(int i = 0, a, b; i < q; ++i)
    {
        cin >> a >> b; --a; --b;
        cout << dist(a, b) << "\n";
    }
}