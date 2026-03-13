#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int LOG = 18;
constexpr int MAXN = 2e5 + 5;
int up[MAXN][LOG];
vector<int> par(MAXN, -1), dep(MAXN, 0);
vector<vector<int>> adj(MAXN);

void dfs(int n)
{
    for(int v: adj[n])
    {
        dep[v] = dep[n]+1;
        dfs(v);
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    par[0] = -1;
    for(int i = 1; i < n; ++i)
    {
        cin >> par[i]; par[i]--;
        adj[par[i]].push_back(i);
    }

    dfs(0);

    for(int i = 0; i < n; ++i)
    {
        up[i][0] = par[i];
        for(int j = 1; j < LOG; ++j)
        {
            if(up[i][j-1] == -1) up[i][j] = -1;
            else up[i][j] = up[up[i][j-1]][j-1];
        }
    }

    for(int i = 0, a, b; i < q; ++i)
    {
        cin >> a >> b; a--;
        int ans = lift(a, b);
        if(ans == -1) cout << -1 << "\n";
        else cout << ans+1 << "\n";
    }    
}