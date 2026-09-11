#include <bits/stdc++.h>
using namespace std;

double dist(pair<int,int> a, pair<int,int> b)
{
    return (double) sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

void dfs(int i, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[i] = true;
    for(auto el: adj[i])
    {
        if(!vis[el]) dfs(el, adj, vis);
    }
}

int main()
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int n; cin >> n;
    vector<pair<pair<int,int>,int>> v;
    for(int i = 0; i < n; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        v.push_back({{a, b}, c});
    }

    vector<vector<int>> adj(n);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(i != j && dist(v[i].first, v[j].first) <= (double) v[i].second)
            {
                adj[i].push_back(j);
            }
        }
    }

    int mx = 0;
    for(int i = 0; i < n; ++i)
    {
        vector<int> vis(n, false);
        dfs(i, adj, vis);
        int curr = 0;
        for(int i = 0; i < n; ++i)
        {
            if(vis[i]) curr++;
        }
        mx = max(mx, curr);
    }

    cout << mx << "\n";
}