#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long long atterra(int n, vector<int> U, vector<int> V)
{
    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++)
    {
        adj[U[i]].push_back(V[i]);
        adj[V[i]].push_back(U[i]);
    }
    vector<ll> mn(n, 1e12);
    vector<bool> path(n, false);

    auto find_path = [&] (auto find_path, int v, int p) -> void
    {
        if(v == n-1) path[v] = true;

        for(int u: adj[v])
        {
            if(u == p) continue;
            find_path(find_path, u, v);
            if(path[u]) path[v] = true;
        }
    };

    auto find_mn = [&] (auto find_mn, int v, int p) -> void
    {
        if(p != -1) mn[v] = min(mn[v], mn[p]+1);

        for(int u: adj[v])
        {
            if(u == p) continue;
            if(!path[u]) mn[v] = 1;
            else find_mn(find_mn, u, v);
            mn[v] = min(mn[v], mn[u]+1);
        }
    };

    find_path(find_path, 0, -1);
    find_mn(find_mn, 0, -1);

    ll tot = 0;
    for(int i = 0; i < n; i++)
    {
        if(path[i])
        {
            tot += mn[i];
            if(mn[i] >= 1e12)
            {
                tot = -1;
                break;
            }
        }
    }

    return tot;
}

// GRADER DI ESEMPIO, NON MODIFICARE

#ifndef EVAL

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N; cin >> N;

    vector<int> U(N - 1), V(N - 1);
    for(int i = 0; i < N - 1; ++i)
        cin >> U[i] >> V[i];

    cout << atterra(N, U, V) << endl;
}

#endif
