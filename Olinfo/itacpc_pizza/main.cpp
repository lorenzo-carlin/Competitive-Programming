#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 1e9+7;

int main()
{
    int n, s, t; cin >> n >> s >> t;
    vector<int> cnt(30, 0);
    for(int i = 0, a; i < n; i++)
    {
        cin >> a;
        for(int j = 0; j < 30; j++)
        {
            if(a & (1 << j))
            {
                cnt[j]++;
            }
        }
    }

    auto fast_exp = [&] (auto fast_exp, ll b, ll exp) -> ll
    {
        if(exp == 1) return b;
        if(exp == 0) return 1;

        ll ans = fast_exp(fast_exp, b, exp/2);
        ans = (ans * ans) % mod;
        if(exp & 1) ans = (ans * b) % mod;

        return ans;
    };

    auto inv_mod = [&] (ll val) -> ll
    {
        return fast_exp(fast_exp, val, mod-2);
    };

    vector<ll> fact(n+1, 1);
    for(int i = 1; i <= n; i++)
        fact[i] = (fact[i-1] * i) % mod;

    auto C = [&] (ll a, ll b) -> ll
    {
        return (fact[a] * inv_mod(fact[b]*fact[a-b] % mod)) % mod;
    };

    ll ans = 1;
    for(int j = 0; j < 30; j++)
    {
        ll sum = 0;
        if(s & (1 << j)) // servibile
        {
            if(t & (1 << j)) // un numero dispari di volte
            {
                int k = (cnt[j] & 1) ? (cnt[j]) : (cnt[j]+1);
                for(int i = k; i <= n; i += 2)
                {
                    sum += C(n-cnt[j], i-cnt[j]);
                    sum %= mod;
                }
            } else // un numero pari di volte
            {
                int k = (cnt[j] & 1) ? (cnt[j]+1) : (cnt[j]);
                if(k == 0) k += 2;
                for(int i = k; i <= n; i += 2)
                {
                    sum += C(n-cnt[j], i-cnt[j]);
                    sum %= mod;
                }
            }
            if(sum == 0) ans = 0;
            ans = (ans * sum) % mod;
        } else // non servibile
        {
            if(cnt[j] || (t & (1 << j))) ans = 0;
        }

    }

    cout << ans << "\n";
}
