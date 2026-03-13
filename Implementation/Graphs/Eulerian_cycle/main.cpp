#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m; cin >> n >> m;
    vector<set<int>> adj(n);
    vector<int> deg(n, 0);
    for(int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
        deg[a]++;
        deg[b]++;
    }

    bool possible = true;
    for(int i = 0; i < n; i++)
        if(deg[i] & 1)
            possible = false;

    int a = 0;
    while(a < n && deg[a] == 0)
        a++;
    if(a == n)
        possible = false;

    vector<int> cycle;
    auto EC = [&] (auto EC, int v) -> void
    {
        while(!adj[v].empty())
        {
            int u = *adj[v].begin();
            adj[v].erase(u);
            adj[u].erase(v);
            EC(EC, u);
        }
        cycle.push_back(v);
    };

    if(possible)
    {
        EC(EC, a);
        if(cycle.size() != m+1)
        {
            possible = false;
        }
    }

    if(!possible)
        cout << "IMPOSSIBLE";
    else
        for(int el: cycle)
            cout << el << " ";
    cout << "\n";
}
