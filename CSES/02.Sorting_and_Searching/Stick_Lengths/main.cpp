#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n; cin >> n;

    vector<ll> v(n);
    for(auto &i: v) cin >> i;

    sort(v.begin(), v.end());

    ll target = v[n/2];

    ll sol = 0;
    for(auto i: v)
    {
        sol += abs(v[n/2] - i);
    }

    cout << sol << "\n";
}