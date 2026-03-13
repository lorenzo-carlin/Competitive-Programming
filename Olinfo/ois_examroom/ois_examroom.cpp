#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll r, c, k; cin >> r >> c >> k;
    r--; c--;
    ll ans = ((r/k) + 1) * ((c/k) + 1);
    cout << ans << "\n";
}