#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
 * IDEA:
 * 1. controllo se ci sono cicli -> se ci sono => IMPOSSIBLE
 * 2. trovo il toposort e ordino la stringa in base a quello
 */

int main()
{
    int n; cin >> n;
    vector<vector<int>> adj(26);
    for(int i = 0; i < n; i++)
    {
        string a, b, c;
        cin >> a >> b >> c;
        int x = a[0] - 'a';
        int y = c[0] - 'a';
        if(b[0] == '>')
        {
            adj[y].push_back(x);
        } else
        {
            adj[x].push_back(y);
        }
    }

    // esistono cicli?
    vector<int> vis(26, 0); // {0, 1, 2}
    bool found = false;
    auto cycle = [&] (auto cycle, int v) -> void
    {
        vis[v] = 1;
        for(int u: adj[v])
        {
            if(vis[u] == 1)
                found = true;
            if(vis[u] == 0)
                cycle(cycle, u);
        }
        vis[v] = 2;
    };

    for(int i = 0; i < 26; i++)
    {
        if(vis[i] == 0)
            cycle(cycle, i);
    }

    string s; cin >> s;

    if(found)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }


    // trovo il toposort
    vector<int> topological;
    vis.assign(26, 0);
    auto toposort = [&] (auto toposort, int v) -> void
    {
        vis[v] = 1;
        for(int u: adj[v])
        {
            if(vis[u] == 0)
            {
                toposort(toposort, u);
            }
        }
        topological.push_back(v);
    };

    for(int i = 0; i < 26; i++)
    {
        if(vis[i] == 0)
        {
            toposort(toposort, i);
        }
    }

    reverse(begin(topological), end(topological));

    vector<int> cnt(26, 0);
    for(char c: s)
    {
        cnt[c-'a']++;
    }


    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < cnt[topological[i]]; j++)
        {
            cout << char('a'+topological[i]);
        }
    }
    cout << "\n";

}





