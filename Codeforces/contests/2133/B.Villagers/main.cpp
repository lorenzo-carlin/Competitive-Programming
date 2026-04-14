#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n; cin >> n;
    vector<ll> g(n);
    for(auto &i: g) cin >> i;

    sort(rbegin(g), rend(g));

    ll tot = 0;
    for(int i = 0; i < g.size(); i++)
    {
        if(i & 1) continue;
        tot += g[i];
    }

    cout << tot << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
