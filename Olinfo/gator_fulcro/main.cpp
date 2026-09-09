#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int del, vector<bool> &vis, vector<vector<int>> &adj)
{
    vis[node] = true;
    for(auto i: adj[node])
    {
        if(!vis[i] && i != del)
        {
            dfs(i, del, vis, adj);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<vector<int>> adj(11);
    for(int i = 0; i < n; ++i)
    {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }

    int mx = 0, mx_ind = -1;
    for(int i = 1; i < 11; ++i)
    {
        vector<bool> vis(11, false);
        dfs(0, i, vis, adj);
        int tmp = 0;
        for(int j = 0; j < 11; ++j)
        {
            if(!vis[j]) tmp++;
        }
        if(tmp > mx)
        {
            mx = tmp;
            mx_ind = i;
        }
    }

    cout << mx_ind+1 << "\n";
}