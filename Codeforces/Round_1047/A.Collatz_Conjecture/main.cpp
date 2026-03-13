#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int k, x; cin >> k >> x;
    while(k--) x *= 2;

    cout << x << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
