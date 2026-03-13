#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m, q; cin >> n >> m >> q;
    vector<ll> a(n), b(m);
    for(auto &i: a) cin >> i;
    for(auto &i: b) cin >> i;

    sort(rbegin(a), rend(a));
    sort(rbegin(b), rend(b));
    vector<ll> pre_a(n+1, 0);
    for(int i = 1; i <= n; i++) pre_a[i] = pre_a[i-1] + a[i-1];
    vector<ll> pre_b(m+1, 0);
    for(int i = 1; i <= m; i++) pre_b[i] = pre_b[i-1] + b[i-1];

    vector<pair<ll,int>> c;
    for(auto el: a) c.push_back({el,0});
    for(auto el: b) c.push_back({el,1});
    sort(rbegin(c), rend(c));
    vector<ll> pre_c(n+m+1, 0);
    vector<ll> cnt_a(n+m+1, 0), cnt_b(n+m+1, 0);
    for(int i = 1; i <= n+m; i++) pre_c[i] = pre_c[i-1] + c[i-1].first;
    for(int i = 1; i <= n+m; i++)
    {
        cnt_a[i] = cnt_a[i-1];
        cnt_b[i] = cnt_b[i-1];
        if(c[i-1].second == 0) cnt_a[i]++;
        else cnt_b[i]++;
    }

    while(q--)
    {
        ll x, y, z; cin >> x >> y >> z;
        if(cnt_a[z] > x) cout << pre_a[x] + pre_b[z-x] << "\n";
        else if(cnt_b[z] > y) cout << pre_b[y] + pre_a[z-y] << "\n";
        else cout << pre_c[z] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
