#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n; cin >> n;
    vector<int> deg(n, 0);
    vector<vector<int>> adj(n);
    for(int i = 0, a, b; i < n-1; i++)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        deg[a]++;
        deg[b]++;
    }

    sort(rbegin(deg), rend(deg));
    int mx1 = deg[0];
    
    for(int i = 0; i < adj[mx1].size(); i++)
    {
        deg[adj[mx1][i]]--;
    }
    sort(rbegin(deg), rend(deg));
    int mx2 = (deg[0] == mx1) ? (deg[1]) : (deg[0]);
    int ans = min(n-2, mx1+mx2-1);

    cout << ans << "\n";
}

int main()
{
    int t; cin >> t;
    while(t--) solve();
}
