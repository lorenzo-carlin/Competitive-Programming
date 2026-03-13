#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 2e5 + 5;
int n;
vector<vector<int>> adj(MAXN);
vector<ll> sons(MAXN, 0), sum(MAXN, 0), dist(MAXN, 0), sol(MAXN);

void dfs1(int node, int p)
{
    sum[node] = dist[node];
    for(int v: adj[node])
    {
        if(v == p) continue;
        dist[v] = dist[node]+1;
        dfs1(v, node);
        sum[node] += sum[v];
        sons[node] += (sons[v]+1);
    }
}

void dfs2(int node, int p)
{
    for(int v: adj[node])
    {
        if(v == p) continue;
        sol[v] = sol[node] - (sons[v]+1) + (n-sons[v]-1);
        dfs2(v, node);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0, a, b; i < n-1; ++i)
    {
        cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(0, -1);
    sol[0] = sum[0];
    dfs2(0, -1);

    for(int i = 0; i < n; ++i) cout << sol[i] << " ";
    cout << "\n";

}