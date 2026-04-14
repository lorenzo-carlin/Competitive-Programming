#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int a, b, x, y; cin >> a >> b >> x >> y;

    if(a > b)
    {
        if(b == a-1 && !(b & 1))
        {
            cout << y << "\n";
        } else
        {
            cout << -1 << "\n";
        }
    } else
    {
        ll ans = 0;
        while(a < b)
        {
            if(a & 1)
            {
                ans += x;
            } else
            {
                ans += min(x, y);
            }
            a++;
        }
        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
