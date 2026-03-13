#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k; cin >> n >> k;
    vector<ll> v(n);
    for(auto &i: v) cin >> i;

    for(int i = 0; i < n; ++i)
    {
        ll r = (v[i] % (k+1));
        v[i] += (k * r);
    }

    for(auto el: v) cout << el << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
