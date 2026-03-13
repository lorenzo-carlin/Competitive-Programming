#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, a; cin >> n >> m >> a;
    ll ans = ((n+a-1)/a)*((m+a-1)/a);

    cout << ans << "\n";
}
