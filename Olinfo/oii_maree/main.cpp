#include <bits/stdc++.h>
using namespace std;

int solve(int N, int M, int T, int* S, int* E)
{
    vector<vector<pair<int,bool>>> adj(N);
    for(int i = 0; i < M; ++i)
    {
        adj[S[i]].push_back({E[i], true});
        adj[E[i]].push_back({S[i], false});
    }

    vector<int> dist(N, 1e9);
    priority_queue<pair<int,int>> q;
    q.push({0, 0});
    while(!q.empty())
    {
        int x = -q.top().first;
        int y = q.top().second;
        q.pop();
        
        if(x >= dist[y]) continue;
        dist[y] = x;

        for(auto i: adj[y])
        {
            int tmp = x+1;
            if(tmp > T && i.second) continue;
            if(!i.second) tmp = max(tmp, T+1);
            if(tmp < dist[i.first]) q.push({-tmp, i.first});
        }
    }

    if(dist[N-1] == 1e9) dist[N-1] = -1;

    return dist[N-1];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, t; cin >> n >> m >> t;
    int s[m], e[m];
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        s[i] = a;
        e[i] = b;
    }
    cout << solve(n, m, t, s, e);
}