#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<vector<pair<int,int>>> adj(n);

    for(int i = 1; i < n; i++)
    {
        char c;
        int a;

        cin >> c >> a;
        if(c == 'B')
        {
            adj[a].push_back({i, 3});
        } else if(c == 'N')
        {
            adj[a].push_back({i, 2});
        } else
        {
            adj[a].push_back({i, 1});
        }
    }

    int ans = 0;
    auto dfs = [&] (auto dfs, int v, int h) -> void
    {
        ans = max(ans, h);
        for(auto [u, q]: adj[v])
        {
            dfs(dfs, u, h+q);
        }
    };

    dfs(dfs, 0, 0);
    cout << ans << "\n";
}
