#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(10000);
vector<bool> vis(10000, false);

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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int count = 0;
    for(int i = 0; i < n; ++i)
    {
        if(!vis[i])
        {
            dfs(i);
            count++;
        }
    }

    count--;

    cout << count;
}