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
    int st = -1, fn = -1;
    for(int i = 0; i < n; i++)
    {
        if(deg[i] & 1)
        {
            if(st == -1)
                st = i;
            else if(fn == -1)
                fn = i;
            else
                possible = false;
        }
    }

    int a = 0;
    while(a < n && deg[a] == 0)
        a++;
    if(a == n)
        possible = false;

    if(!possible)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

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

    if(st != -1 && fn != -1)
    {
        adj[st].insert(fn);
        adj[fn].insert(st);
    }

    EC(EC, a);
    if(cycle.size() != m+1)
        possible = false;

    if(possible)
    {
        if(st == -1 && fn == -1)
        {
            for(int el: cycle)
                cout << el << " ";
            cout << "\n";
        } else
        {
            int x;
            for(int i = 0; i < cycle.size()-1; i++)
                if((cycle[i] == st && cycle[i+1] == fn) || (cycle[i] == fn) && (cycle[i+1] == st))
                    x = i;
            vector<int> path;
            for(int i = x+1; i < cycle.size(); i++)
                path.push_back(cycle[i]);
            for(int i = 1; i <= x; i++)
                path.push_back(cycle[i]);
            for(int el: path)
                cout << el << " ";
            cout << "\n";
        }
    } else
    {
        cout << "IMPOSSIBLE\n";
    }
}
