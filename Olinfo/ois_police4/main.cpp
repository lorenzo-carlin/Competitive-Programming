#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, r, t, l; cin >> n >> r >> t >> l;
    vector<ll> v(n+1);
    v[0] = 0;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
    }
    v.push_back(l);
    ll timer = t*2;

    vector<vector<ll>> dp(n+2, vector<ll> (r+1, 1e15));
    // dp[pos][sem] = tempo minimo necessario per raggiungere la tappa
    // 'pos', skippando 'sem' semafori
    for(int j = 0; j <= r; ++j) dp[0][j] = 0;
    for(int i = 0; i <= n; ++i)
    {
        for(int j = 0; j <= r; ++j)
        {
            ll tmp = 1e15;
            if(dp[i][j]%timer >= t) // se devo aspettare
            {
                // non skippo
                tmp = dp[i][j] + (timer-(dp[i][j]%timer)) + (v[i+1] - v[i]);
                dp[i+1][j] = min(dp[i+1][j], tmp);
                // skippo
                if(j != r)
                {
                    tmp = dp[i][j] + (v[i+1] - v[i]);
                    dp[i+1][j+1] = min(dp[i+1][j+1], tmp);
                }
            } else
            {
                tmp = dp[i][j] + (v[i+1] - v[i]);
                dp[i+1][j] = min(dp[i+1][j], tmp);
            }
        }
    }

    ll mn = 1e15;
    for(int j = 0; j <= r; ++j)
    {
        mn = min(mn, dp[n+1][j]);
    }
    cout << mn << "\n";
}