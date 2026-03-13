#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define f first
#define s second
 
const ll INF = 1e18;
 
void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, set<int> &st)
{
    vis[node] = true;
 
    for(auto el: adj[node])
    {
        if(!vis[el]) dfs(el, adj, vis, st);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<pair<pair<int,int>,int>> edges(m);
    for(int i = 0; i < m; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        edges[i] = {{a, b}, c};
        adj[a].push_back(b);
    }
 
    vector<ll> dist(n, -INF);
    dist[0] = 0;
    for(int i = 0; i < n-1; ++i)
    {
        for(auto el: edges)
        {
            if(dist[el.f.f] > -INF)
            {
                dist[el.f.s] = max(dist[el.f.s], dist[el.f.f]+el.s);
            }
        }
    }
 
    // salvo i nodi che cambiano la loro dist alla n-esima iterazione
    set<int> st;
    for(auto el: edges)
    {
        if(dist[el.f.f] > -INF)
        {
            if((dist[el.f.f]+el.s) > dist[el.f.s])
            {
                st.insert(el.f.s);
            }
        }
    }
    
    bool cycle = false;
    for(auto el: st)
    {
        vector<bool> vis(n, false);
        dfs(el, adj, vis, st);
        if(vis[n-1]) cycle = true;
    }
 
    if(cycle) cout << -1 << "\n";
    else cout << dist[n-1] << "\n";
}
