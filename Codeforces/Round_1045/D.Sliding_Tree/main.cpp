#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0, a, b; i < n-1; i++)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool line = true;
    for(int i = 0; i < n; ++i)
    {
        if(adj[i].size() > 2)
        {
            line = false;
        }
    }

    if(line)
    {
        cout << -1 << "\n";
        return;
    }

    // calcolo il diametro dell'albero
    vector<int> dist(n, 1e9);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        for(int u: adj[v])
        {
            if(dist[u] > dist[v]+1)
            {
                dist[u] = dist[v]+1;
                q.push(u);
            }
        }
    }

    int st = -1, mx = 0;
    for(int i = 0; i < n; ++i)
    {
        if(dist[i] > mx)
        {
            mx = dist[i];
            st = i;
        }
    }

    dist.assign(n, 1e9);
    vector<int> par(n, -1);
    q.push(st);
    dist[st] = 0;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        for(int u: adj[v])
        {
            if(dist[u] > dist[v]+1)
            {
                dist[u] = dist[v]+1;
                par[u] = v;
                q.push(u);
            }
        }
    }

    int end = -1;
    mx = 0;
    for(int i = 0; i < n; ++i)
    {
        if(dist[i] > mx)
        {
            mx = dist[i];
            end = i;
        }
    }

    int idx = end;
    while(par[idx] != -1)
    {
        if(adj[par[idx]].size() > 2)
        {
            for(int u: adj[par[idx]])
            {
                if(u != idx && (par[par[idx]] == -1 || u != par[par[idx]]))
                {
                    cout << idx+1 << " " << par[idx]+1 << " " << u+1 << "\n";
                    return;
                }
            }
        }
        idx = par[idx];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
