#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m; cin >> n >> m;
    vector<int> alt(n);
    for(auto &i: alt) cin >> i;
    
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis(n, false);
    int curr = 0, prec = -1;
    while(!vis[curr])
    {
        vis[curr] = true;
        int mn = 1e9, ind_mn = -1;
        for(int i = 0; i < adj[curr].size(); ++i)
        {
            int el = adj[curr][i];
            if(el != prec && alt[el] < mn)
            {
                mn = alt[el];
                ind_mn = el;
            }
        }

        if(ind_mn == -1) break;

        prec = curr;
        curr = ind_mn;
    }

    cout << curr << "\n";
}