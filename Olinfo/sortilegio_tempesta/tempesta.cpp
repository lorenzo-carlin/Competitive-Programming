#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long long atterra(int n, vector<int> u, vector<int> v)
{
    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++)
    {
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }

    vector<bool> onpath(n, false);
    auto find_path = [&] (auto find_path, int v, int p) -> void
    {
        if(v == n-1)
            onpath[v] = true;

        for(int u: adj[v])
        {
            if(u == p) continue;
            find_path(find_path, u, v);
            if(onpath[u])
                onpath[v] = true;
        }
    };

    find_path(find_path, 0, -1);

    queue<int> q;

    vector<ll> dist(n, 1e9);
    for(int i = 0; i < n; i++)
    {
        if(!onpath[i])
        {
            dist[i] = 0;
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        for(int u: adj[v])
        {
            if(dist[v]+1 < dist[u])
            {
                dist[u] = dist[v]+1;
                q.push(u);
            }
        }
    }

    ll ans = 0;
    bool possible = true;
    for(int i = 0; i < n; i++)
    {
        if(onpath[i])
        {
            if(dist[i] >= 1e9)
                possible = false;
            ans += dist[i];
        }
    }

    if(!possible) ans = -1;

    return ans;
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
