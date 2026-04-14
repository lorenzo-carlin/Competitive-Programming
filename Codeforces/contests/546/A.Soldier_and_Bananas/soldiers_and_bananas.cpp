#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll k, n, w; cin >> k >> n >> w;
    ll tot = (w * (w + 1) / 2) * k;
    ll sol = tot - n;
    sol = max(sol, (ll)0);
    cout << sol << "\n";
}