#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve(ll n, ll m, ll h, ll w)
{
    if(gcd(h, w) != 1)
        return false;
    if((h + w) % 2 == 0)
        return false;
    if(max(n, m) < 2*max(h, w))
        return false;
    if(min(n, m) < h+w)
        return false;
    return true;
}

int main()
{
    int t; cin >> t;
    while(t--)

    {
        ll n, m, h, w; cin >> n >> m >> h >> w;
        if(solve(n, m, h, w)) cout << "YES\n";
        else cout << "NO\n";
    }
}
