#include <bits/stdc++.h>
using namespace std;

int sol = 0;

void dfs(int node, int min, vector<vector<int>> &adj, map<int,int> &brv)
{
    for(auto i: adj[node])
    {
        if(brv[i] <= min)
        {
            dfs(i, brv[i], adj, brv);
        } else
        {
            sol++;
            dfs(i, min, adj, brv);
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
    vector<vector<int>> adj(n);
    map<int, int> brv;
    for(int i = 0; i < n; ++i)
    {
        int a, b; cin >> a >> b;
        brv[i] = a;
        if(b != -1)
        {
            adj[b].push_back(i);
        }
    }

    dfs(0, brv[0], adj, brv);

    cout << sol << "\n";
}