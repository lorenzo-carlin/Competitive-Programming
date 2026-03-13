#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define f first
#define s second

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, c, k; cin >> n >> m >> c >> k;

    vector<bool> air(n, false);
    for(int i = 0; i < k; ++i)
    {
        int a; cin >> a;
        air[a-1] = true;
    }

    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0; i < m; ++i)
    {
        int a, b, d; cin >> a >> b >> d;
        a--; b--;
        if(d >= 20) continue;
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
    }

    vector<int> dist(n, 1e9);

    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push({-0, {0, 20}});

    while(!pq.empty())
    {
        auto el = pq.top();
        pq.pop();

        if(el.s.s <= 0) continue;

        if(-el.f >= dist[el.s.f]) continue;
        dist[el.s.f] = -el.f;

        for(auto i: adj[el.s.f])
        {
            int q = -el.f + i.s;
            if(air[el.s.f]) pq.push({-q, {i.f, 20}});
            else pq.push({-q, {i.f, el.s.s-i.s}});
        }
    }

    c--;
    
    if(dist[c] == 1e9) cout << -1 << "\n";
    else cout << dist[c] << "\n";
}