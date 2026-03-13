#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m, a, b; cin >> n >> m >> a >> b;
    a--; b--;
    vector<set<int>> adj(n);
    for(int i = 0, x, y; i < m; i++)
    {
        cin >> x >> y;
        x--; y--;
        adj[x].insert(y);
        adj[y].insert(x);
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

    EP(EP, a);

    reverse(begin(path), end(path));

    for(int i = 0; i < m; i++)
    {
        cout << path[i]+1 << " " << path[i+1]+1 << "\n";
    }
}
