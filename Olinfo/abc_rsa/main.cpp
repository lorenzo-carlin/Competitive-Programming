#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int fast_exp(int base, int exp, int mod)
{
    if(exp == 0) return 1;
    if(exp == 1) return base%mod;
    ll f = fast_exp(base, exp/2, mod);
    ll ans = (f*f) % mod;
    if(exp % 2) ans = (ans * base) % mod;
    return ans;
}

void decifra(int N, int d, int L, int messaggio[], char plaintext[])
{
    for(int i = 0; i < L; ++i)
    {
        int tmp = messaggio[i];
        char c = (fast_exp(tmp, d, N));
        plaintext[i] = c;
    }
}