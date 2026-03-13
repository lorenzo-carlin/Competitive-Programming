#include <bits/stdc++.h>
using namespace std;

int MAX = 1e5;
vector<vector<int>> adj(MAX);
vector<bool> vis(MAX, false);

void dfs(int num)
{
    vis[num] = true;
    for(auto i:adj[num])
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int count = 0;
    int st, fn;
    vector<pair<int,int>> roads;
    for(int i = 1; i <= n; ++i)
    {
        if(!vis[i])
        {
            dfs(i);
            count++;
            if(i > 1)
            {
                fn = i;
                roads.push_back({st, fn});
            }
            st = i;
        }
    }
    count--;
    cout << count << endl;
    for(int i = 0; i < roads.size(); ++i)
    {
        cout << roads[i].first << " " << roads[i].second << endl;
    }
}