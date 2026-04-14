#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int x, n; cin >> x >> n;
    if(n & 1) cout << x << "\n";
    else cout << 0 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
