#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int a, b, c; cin >> a >> b >> c;
    if(a != b && a != c) cout << a << "\n";
    else if(b != a && b != c) cout << b << "\n";
    else cout << c << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
