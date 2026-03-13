#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, st, fn; cin >> n >> m >> st >> fn; st--; fn--;
    vector<pair<int,int>> adj(n, {-1, 1e9});
    for(int i = 0; i < m; ++i)
    {
        int a, b, c; cin >> a >> b >> c; a--; b--;
        if(c < adj[a].second)
        {
            adj[a] = {b, c};
        }
        if(c < adj[b].second)
        {
            adj[b] = {a, c};
        }
    }

    vector<bool> vis(n, false);
    int curr = st, prec = -1, sol = 0;
    while(!vis[curr])
    {
        if(curr == fn)
        {
            cout << sol << "\n";
            return 0;
        }
        vis[curr] = true;
        prec = curr;
        curr = adj[curr].first;
        sol++;
    }

    cout << -1 << "\n";
}