#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<int> status;
bool fn = false, sol = false;
int l = 0, r = 0;
vector<int> path;

void dfs(int node)
{
    status[node] = 1;

    for(int v: adj[node])
    {
        if(!status[v]) dfs(v);
        else if(status[v] == 1 && !fn)
        {
            sol = fn = true;
            l = v, r = node;
        }

        if(fn) break;
    }

    status[node] = 2;

    if(sol)
    {
        path.push_back(node);
        if(node == l) sol = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    adj.resize(n+1);
    status.resize(n+1, 0);

    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i = 1; i <= n; ++i)
    {
        if(!fn && !status[i]) dfs(i);
    }

    reverse(begin(path), end(path));

    if(path.size())
    {
        cout << path.size()+1 << "\n";
        for(int el: path) cout << el << " ";
        cout << path.front() << "\n";
    } else cout << "IMPOSSIBLE\n";
}