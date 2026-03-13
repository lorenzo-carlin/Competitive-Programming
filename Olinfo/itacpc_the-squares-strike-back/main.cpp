#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    map<ll,ll> mp;
    for(ll i = 0, a, b; i < n; i++)
    {
        cin >> a >> b;
        mp[a-b]++;
    }

    ll ans = 0;
    for(auto el: mp)
    {
        ll x = el.second;
        ans += (x*(x-1))/2;
    }

    cout << ans << "\n";
}
