#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int mod = 1e9+7;
vector<ll> fact(1e6+1);
 
ll fast_exp(int b, int exp)
{
    if(exp == 0) return 1;
    if(exp == 1) return b;
    ll ans = fast_exp(b, exp/2);
    ans = ans*ans % mod;
    if(exp % 2) ans = ans * b % mod;
    return ans;
}
 
ll inverse(int n)
{
    return fast_exp(n, mod-2);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    fact[0] = 1;
    for(int i = 1; i <= 1e6; ++i) fact[i] = fact[i-1]*i % mod;
 
    int n; cin >> n;
    while(n--)
    {
        int a, b; cin >> a >> b;
        cout << fact[a] * inverse(fact[b] * fact[a-b] % mod) % mod << "\n";
    }
}
