#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m, x, y; cin >> n >> m >> x >> y;
    for(int i = 0, a; i < n; ++i) cin >> a;
    for(int i = 0, a; i < m; ++i) cin >> a;
    cout << m+n << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
