#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll t; cin >> t;
    for(ll c = 1; c <= t; ++c)
    {
        ll n, l, d; cin >> n >> l >> d;
        vector<ll> x(n), p(n), s(n);
        for(ll i = 0; i < n; ++i) cin >> x[i] >> p[i] >> s[i];

        vector<ll> dp(n, -1e9);
        // dp[i] = massimo numero di punti ottenibili nell'llervallo (0, Si)
        // se ottiene punti dall'ostacolo i

        for(ll i = 0; i < n; ++i)
        {
            if(s[i] >= x[i]) dp[i] = p[i];
            for(ll j = 0; j < i; ++j)
            {
                if(s[i] - s[j] >= abs(x[i] - x[j]))
                {
                    dp[i] = max(dp[i], dp[j]+p[i]);
                }
            }
        }

        ll sol = 0;
        for(ll i = 0; i < n; ++i)
        {
            sol = max(sol, dp[i]);
        }

        cout << "Case #" << c << ": " << sol << "\n";
    }
}