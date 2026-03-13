#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    vector<int> cnt(26, 0);
    for(char c: s)
        cnt[c-'a']++;

    int n = s.size();
    vector<ll> fact(n+1, 1);
    for(int i = 1; i <= n; i++)
        fact[i] = (fact[i-1]*i) % mod;

    auto binary_exp = [&] (auto binary_exp, int b, int exp) -> ll
    {
        if(exp == 0) return 1LL;
        if(exp == 1) return b;

        ll tmp = binary_exp(binary_exp, b, exp/2);
        tmp = (tmp * tmp) % mod;
        if(exp & 1)
            tmp = (tmp * b) % mod;

        return tmp;
    };

    auto mod_inverse = [&] (ll val) -> ll
    {
        return binary_exp(binary_exp, val, mod-2);
    };

    ll ans = fact[n];

    for(int i = 0; i < 26; i++)
    {
        if(cnt[i])
            ans = (ans * mod_inverse(fact[cnt[i]])) % mod;
    }

    cout << ans << "\n";
}
