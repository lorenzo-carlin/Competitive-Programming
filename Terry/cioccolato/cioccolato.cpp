#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for(int cas = 1; cas <= t; ++cas)
    {
        ll n, m, k; cin >> n >> m >> k;
        
        if(abs(n-m) >= k)
        {
            ll a = max(n, m);
            ll b = min(n, m);
            a -= k;

            ll sol = a*b;

            cout << "Case #" << cas << ": " << sol << "\n";
        } else
        {
            ll a = max(n, m);
            ll b = min(n, m);
            k -= (a-b);
            a = b;
            a -= (k/2);
            k -= (k/2);
            b -= k;

            ll sol = a*b;

            cout << "Case #" << cas << ": " << sol << "\n";
        }
    }

    return 0;
}