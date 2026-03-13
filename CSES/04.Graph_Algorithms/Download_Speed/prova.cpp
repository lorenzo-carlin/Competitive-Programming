#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<vector<ll>> cap(n, vector<ll> (n, 0));
    vector<vector<int>> adj(n);
    for(int i = 0, a, b, c; i < m; i++)
    {
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        cap[a][b] += c;
    }

    ll flow = 0;
    vector<int> parent(n);

    auto bfs = [&] (int st, int fn, vector<int> &parent) -> ll
    {
        parent.assign(n, -1);
        parent[st] = -2;
        queue<pair<int,ll>> q;
        q.push({st, INF});

        while(!q.empty())
        {
            int v = q.front().first;
            ll d = q.front().second;
            q.pop();

            for(int u: adj[v])
            {
                if(parent[u] == -1 && cap[v][u] > 0)
                {
                    ll newflow = min(d, cap[v][u]);
                    parent[u] = v;
                    if(u == fn)
                        return newflow;
                    q.push({u, newflow});
                }
            }
        }

        return 0;
    };

    ll tmp;
    while(tmp = bfs(0, n-1, parent))
    {
        flow += tmp;
        int cur = n-1;
        while(cur != 0)
        {
            int prev = parent[cur];
            cap[cur][prev] += tmp;
            cap[prev][cur] -= tmp;
            cur = prev;
        }
    }

    cout << flow << "\n";
}
