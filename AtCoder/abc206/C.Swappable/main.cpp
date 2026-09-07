#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n; cin >> n;
    
    vector<ll> v(n);
    for(auto &i:v) cin >> i;
    
    sort(v.begin(), v.end());

    ll ans = (n *(n-1)) / 2;

    ll cnt = 0;
    ll c = 0;
    for(ll i = 1; i < n; ++i)
    {
        c++;
        if(i == (n-1) && v[i] == v[i-1])
            c++;
        if(v[i] != v[i-1] || i == (n-1))
        {
            cnt += (c * (c - 1)) / 2;
            c = 0;
        }
    }

    ans -= cnt;
    cout << ans;
}