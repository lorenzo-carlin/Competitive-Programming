#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll m, n, d = 0, s = 0; cin >> m >> n;
    vector<ll> a, b;
    for(ll i = 0; i < n; ++i)
    {
        int x, y; cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }
    for(ll i = 0; i < n; ++i)
    {
        if(a[i]*b[i] <= s)
        {
            s -= a[i]*b[i];
        } else
        {
            a[i] -= s/b[i];
            ll oneday = m/b[i];
            d += a[i]/oneday;
            a[i] = a[i] % oneday;
            if(a[i] > 0)
            {
                d++;
                s = m - a[i]*b[i];
            } else
            {
                s = m - b[i]*oneday;
            }
        }
    }
    cout << d << " " << s << "\n";
}