/*
 * Modular Inverse
 * Computes the modular multiplicative inverse of an integer using the
 * Extended Euclidean Algorithm.
 */


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 1e9+7;

ll fast_exp(ll b, ll exp)
{
    if(exp == 0) return 0;
    if(exp == 1) return b;

    ll ans = fast_exp(b, exp/2);
    ans = (ans * ans) % mod;
    if(b & 1) ans = (ans * b) % mod;

    return ans;
}

ll mod_inv(ll v)
{
    return fast_exp(v, mod-2);
}

int main()
{
    ll b, exp;
    cin >> b >> exp;

    cout << fast_exp(b, exp) << "\n";
}
