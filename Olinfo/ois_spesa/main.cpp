#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m, k; cin >> n >> m >> k;
    vector<int> markets(k);
    for(int i = 0; i < k; i++)
    {
        cin >> markets[i];
        markets[i]--;
    }

    vector<vector<int>> adj(n);
    for(int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dist1(n, 1e9), distN(n, 1e9);

    dist1[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        for(int u: adj[v])
        {
            if(dist1[u] > dist1[v]+1)
            {
                dist1[u] = dist1[v]+1;
                q.push(u);
            }
        }
    }

    distN[n-1] = 0;
    q.push(n-1);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        for(int u: adj[v])
        {
            if(distN[u] > distN[v]+1)
            {
                distN[u] = distN[v]+1;
                q.push(u);
            }
        }
    }

    int val = 1e9;
    for(int m: markets)
    {
        val = min(val, dist1[m]+distN[m]);
    }

    cout << val << "\n";
}
