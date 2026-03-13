#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fast_exp(ll b, ll exp)
{
    if(exp == 0) return 1;
    if(exp == 1) return b;

    ll ans = fast_exp(b, exp/2);
    ans *= ans;
    if(exp & 1) ans *= b;

    return ans;
}

void solve()
{
    ll n; cin >> n;
    vector<ll> v;
    while(n != 0)
    {
        v.push_back(n % 3);
        n /= 3;
    }

    ll tot = 0;
    for(ll i = 0; i < v.size(); ++i)
    {
        tot += (fast_exp(3, i+1) * v[i]);;
        if(i != 0) tot += (i * fast_exp(3, i-1) * v[i]);
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
