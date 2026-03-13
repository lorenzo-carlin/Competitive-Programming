#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, m; cin >> n >> m;

    ll mx = (n % 3 == 0) ? (n/3) : (n/3 + 1);
    if(m > (n - mx + 1)) cout << "filippo\n";
    else if(m == (n - mx + 1)) cout << "draw\n";
    else cout << "tommaso\n";
}

int main()
{
    int t; cin >> t;
    while(t--) solve();
}
