#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m, c; cin >> n >> m >> c;
    vector<int> v(n);
    for(int &i: v) cin >> i;

    vector<ll> ps(n+1, 0);
    for(int i = 0; i < n; ++i)
    {
        ps[i+1] = ps[i] + v[i];
    }

    vector<int> pre(n), suf(n);
    int cnt = 0, sum = 0;
    for(int i = 0; i < n; ++i)
    {
        pre[i] = cnt;
        sum += v[i];
        if(sum >= c)
        {
            cnt++;
            sum = 0;
        }
    }
    if(cnt < m)
    {
        cout << -1 << "\n";
        return;
    }

    cnt = 0, sum = 0;
    for(int i = n-1; i >= 0; i--)
    {
        suf[i] = cnt;
        sum += v[i];
        if(sum >= c)
        {
            cnt++;
            sum = 0;
        }
    }

    ll ans = 0;
    for(int j = n-1; j >= 0; j--)
    {
        ll bound = m - suf[j];
        int pos = (lower_bound(begin(pre), end(pre), bound) - begin(pre));
        ll tot = ps[j+1] - ps[pos];
        ans = max(tot, ans);
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
