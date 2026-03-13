#include <bits/stdc++.h>
using namespace std;

bool possible = true;

void dfs(int i, bool cond, vector<vector<int>> &adj, vector<int> &team)
{
    int nxt = (cond) ? 1 : 2;
    for(auto el: adj[i])
    {
        if(team[el] == 0)
        {
            team[el] = nxt;
            dfs(el, !cond, adj, team);
        } else if(team[el] != nxt)
        {
            possible = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<int> team(n, 0);

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i < n; ++i)
    {
        if(team[i] == 0)
        {
            team[i] = 1;
            dfs(i, false, adj, team);
        }
    }

    if(possible)
    {
        for(int i = 0; i < n; ++i)
        {
            cout << team[i] << " ";
        }
        cout << "\n";
    } else
    {
        cout << "IMPOSSIBLE\n";
    }
}