#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fast_exp(ll b, ll exp, ll mod)
{
    if(exp == 0) return 1;
    if(exp == 1) return b;

    ll ans = fast_exp(b, exp/2, mod);
    ans = ans*ans % mod;
    if(exp % 2) ans = ans*b % mod;

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll mod = 1e9+7;

    int n; cin >> n;
    while(n--)
    {
        ll a, b, c; cin >> a >> b >> c;
        ll esp = fast_exp(b, c, mod-1);
        ll ans = fast_exp(a, esp, mod);
        cout << ans << "\n";
    }
}