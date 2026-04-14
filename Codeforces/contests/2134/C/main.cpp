#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n; cin >> n;
    vector<ll> v(n);
    for(auto &i: v) cin >> i;

    ll rem = 0;
    for(int i = 0; i < n-1; i++)
    {
        if(!(i & 1)) continue;

        rem += max(0LL, v[i-1]-v[i]);
        v[i-1] -= max(0LL, v[i-1]-v[i]);

        rem += max(0LL, v[i+1]-v[i]);
        v[i+1] -= max(0LL, v[i+1]-v[i]);

        ll to_rem = max(0LL, (v[i+1]+v[i-1]-v[i]));

        rem += to_rem;
        v[i-1] -= max(0LL, to_rem - v[i+1]);
        v[i+1] -= min(v[i+1], to_rem);
    }

    if(!(n & 1))
    {
        rem += max(0LL, v[n-2]-v[n-1]);
    }

    cout << rem << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
