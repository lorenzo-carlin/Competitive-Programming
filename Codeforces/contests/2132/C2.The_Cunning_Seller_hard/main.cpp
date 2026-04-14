#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, k; cin >> n >> k;

    vector<ll> v, p;
    p.push_back(1);
    for(int i = 1; i <= 38; i++) p.push_back(p.back()*3);

    ll cnt = 0;
    while(n != 0)
    {
        v.push_back(n % 3);
        cnt += (n % 3);
        n /= 3;
    }

    if(cnt > k)
    {
        cout << -1 << "\n";
        return;
    }

    ll rem = k - cnt;
    for(ll i = v.size()-1; i > 0; i--)
    {
        ll mn = min(rem/2, v[i]);
        v[i] -= mn;
        v[i-1] += 3*mn;
        rem -= 2*mn;
    }

    ll tot = 0;
    for(ll i = 0; i < v.size(); ++i)
    {
        tot += (p[i+1] * v[i]);;
        if(i != 0) tot += (i * p[i-1] * v[i]);
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
