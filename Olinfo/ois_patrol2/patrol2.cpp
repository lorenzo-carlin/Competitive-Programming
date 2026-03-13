#include <bits/stdc++.h>
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, l; cin >> n >> m >> l;
    vector<vector<int>> adj(n);
    vector<int> dist(n, INT_MAX);
    vector<bool> vis(n, false);
    vector<int> padre(n, -1);
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> police(l);
    for(auto &i:police) cin >> i;

    // calcolo cammino minimo 
    queue<int> q;
    vis[0] = true;
    dist[0] = 0;
    q.push(0);
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        for(auto i:adj[t])
        {
            if(!vis[i])
            {
                q.push(i);
                dist[i] = dist[t]+1;
                padre[i] = t;
                vis[i] = true;
            }
        }
    }

    stack<int> s;
    int ind = n-1;
    s.push(ind);
    while(padre[ind] != -1)
    {
        ind = padre[ind];
        s.push(ind);
    }

    int cnt = 0, sz = s.size(), j = 0;
    s.pop();
    while(!s.empty())
    {
        if(police[(j+1)%l] != s.top())
        {
            s.pop();
        }
        cnt++;
        j++;
    }

    cout << cnt;
}