#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b, t; cin >> a >> b >> t;
    int dif = 24 - b;
    b += dif;
    a += dif;
    ll div = (t / 24) * (b - a);
    t = t % 24;
    ll ans = div;
    if(t > a)
        ans += (t - a);
    cout << ans;
    return 0;
}