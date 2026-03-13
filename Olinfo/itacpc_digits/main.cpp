#include <iostream>
using namespace std;
using ll = long long;

ll sum(ll v)
{
    ll ans = 0;
    while(v > 0)
    {
        ans += (v % 10);
        v /= 10;
    }
    return ans;
}

int main()
{
    int d, n; cin >> d >> n;
    ll s = d;
    for(ll i = 2; i <= n; i++)
        s = (s + s + sum(i));

    cout << s << "\n";
}
