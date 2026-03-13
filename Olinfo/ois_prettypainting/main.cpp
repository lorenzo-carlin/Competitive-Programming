#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;

    vector<int> k(n);
    for(int &i: k) cin >> i;

    vector<int> a(n-1), b(n-1);
    for(int &i: a) cin >> i;
    for(int &i: b) cin >> i;

    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0; i < n-1; i++)
    {
        adj[i+1].push_back({a[i], b[i]});
        adj[a[i]].push_back({i+1, b[i]});
    }

    for(int i = 0; i < n; i++)
    {
        cout << "i: ";
        for(auto [u, q]: adj[i]) cout << u << " ";
        cout << "\n";
    }

    vector<array<int,2>> dp(n, {0, 0});
    vector<bool> vis(n, false);
    auto dfs = [&] (auto dfs, int n, int p) -> void
    {
        vector<array<int,3>> v;

        for(auto [u, q]: adj[n])
        {
            if(u == p) continue;
            dfs(dfs, u, n);
            v.push_back({dp[u][0], u, 0});
            v.push_back({dp[u][1]+q, u, 1});
        }

        sort(rbegin(v), rend(v));

        cout << "\n\n";
        cout << n << ":\n";

        for(auto el: v)
            cout << el[0] << " " << el[1] << " " << el[2] << "\n";

        int chosen = 0, tot = 0;
        bool saturo0 = false, saturo1 = false;
        for(int i = 0; i < v.size(); i++)
        {
            if(vis[v[i][1]]) continue;
            vis[v[i][1]] = true;

            if(v[i][2] == 1)
                chosen++;
            if(chosen == k[n])
                saturo1 = true;
            if(chosen == k[n]+1)
                saturo0 = true;
            if(v[i][2] == 0)
            {
                dp[n][0] += v[i][0];
                dp[n][1] += v[i][0];
            }
            if(v[i][2] == 1 && !saturo1)
            {
                dp[n][1] += v[i][0];
            }
            if(v[i][2] == 1 && !saturo0)
            {
                dp[n][0] += v[i][0];
            }
        }
    };

    dfs(dfs, 0, -1);

    for(int i = 0; i < n; i++)
    {
        cout << i << ": " << dp[i][0] << " " << dp[i][1] << "\n";
    }

    cout << dp[0][0] << "\n";
}        
