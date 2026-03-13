#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<set<int>> adj(n);
    vector<int> deg(n, 0);

    for(int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        a--; b--;
        adj[a].insert(b);
        adj[b].insert(a);
        deg[a]++;
        deg[b]++;
    }

    bool possible = true;
    for(int i = 0; i < n; i++)
    {
        if(deg[i] & 1)
        {
            possible = false;
        }
    }

    vector<int> path;
    auto EP = [&] (auto EP, int v) -> void
    {
        while(!adj[v].empty())
        {
            int u = *adj[v].begin();
            adj[v].erase(u);
            adj[u].erase(v);
            EP(EP, u);
        }
        path.push_back(v);
    };

    EP(EP, 0);

    if(path.size() != m+1)
    {
        possible = false;
    }

    if(!possible)
    {
        cout << "IMPOSSIBLE\n";
    } else
    {
        for(int el: path) cout << el+1 << " ";
        cout << "\n";
    }
}
