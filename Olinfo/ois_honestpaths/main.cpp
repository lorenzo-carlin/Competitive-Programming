#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 1e18;

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<array<int,2>>> adj(n);

    for(int i = 0, a, b, c; i < m; i++)
    {
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vector<ll> dist(n, inf);
    dist[n-1] = 0;
    priority_queue<array<ll,2>> pq;
    pq.push({0, n-1});
    while(!pq.empty())
    {
        ll d = -pq.top()[0];
        int v = pq.top()[1];
        pq.pop();

        for(auto [u, w]: adj[v])
        {
            if(d+w < dist[u])
            {
                dist[u] = d+w;
                pq.push({-(d+w), u});
            }
        }
    }

    vector<int> v(n);
    iota(begin(v), end(v), 0);

    auto cmp = [&] (int a, int b) -> bool
    {
        if(dist[a] != dist[b]) return dist[a] < dist[b];
        else return a < b;
    };

    sort(begin(v), end(v), cmp);

    vector<ll> dp(n, 0);
    vector<int> par(n, -1);
    ll mx = 0;
    int mx_idx = -1;
    for(int i = 0; i < n; i++)
    {
        int x = v[i];
        for(auto [u, q]: adj[x])
        {
            if(dist[u] < dist[x] && dp[x] < dp[u]+q)
            {
                dp[x] = dp[u]+q;
                par[x] = u;
            }
        }
        if(dp[x] > mx)
        {
            mx = dp[x];
            mx_idx = x;
        }
    }

    cout << mx << " ";
    vector<int> ans;
    while(mx_idx != -1)
    {
        ans.push_back(mx_idx);
        mx_idx = par[mx_idx];
    }

    cout << ans.size() << "\n";
    for(int el: ans) cout << el+1 << " ";
    cout << "\n";
}
