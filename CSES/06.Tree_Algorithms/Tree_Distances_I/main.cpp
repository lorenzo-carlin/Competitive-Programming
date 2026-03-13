#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<int,int> sol = {0, 0};
vector<vector<int>> adj;

void dfs(int n, int p, vector<int> &v)
{
    sol = max(sol, {v[n], n});
    for(auto u: adj[n])
    {
        if(u == p) continue;
        v[u] = v[n]+1;
        dfs(u, n, v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    adj.resize(n);
    for(int i = 0; i < n-1; ++i)
    {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> d(n, 0);
    dfs(0, -1, d);

    vector<int> d_e1(n, 0);
    int e1 = sol.second;
    sol = {0, 0};
    dfs(e1, -1, d_e1);

    vector<int> d_e2(n, 0);
    int e2 = sol.second;
    sol = {0, 0};
    dfs(e2, -1, d_e2);

    for(int i = 0; i < n; ++i)
        cout << max(d_e1[i], d_e2[i]) << " ";
    cout << "\n";
}