#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n; cin >> n;
    vector<pair<ll,ll>> v;
    for(ll i = 0; i < n; ++i)
    {
        ll a; cin >> a;
        v.push_back({a, i});
    }
    sort(v.rbegin(), v.rend());

    ll ind = 0, sol = 0;
    for(auto el: v)
    {
        sol += abs(el.second - ind);
        ind = el.second;
    }

    cout << sol << "\n";
}