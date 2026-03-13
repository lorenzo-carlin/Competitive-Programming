#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    string s; cin >> s;

    // nxt[i][k] = j: finestra massimale [i ... j] che ha k caratteri distinti
    // se tale finestra non esiste j = -1
    vector<vector<int>> nxt(n, vector<int> (27, -1));
    for(int i = 0; i < n; i++)
        nxt[i][0] = i;
    for(int k = 1; k <= 26; k++)
    {
        vector<int> occ(26, 0);
        int distinct = 0;
        int r = -1;

        for(int l = 0; l < n; l++)
        {
            while(r + 1 < n && distinct + (occ[s[r + 1] - 'a'] == 0 ? 1 : 0) <= k)
            {
                r++;
                if(occ[s[r] - 'a']++ == 0) distinct++;
            }
            if(distinct == k) nxt[l][k] = r;
            else nxt[l][k] = -1;

            if(l <= r)
                if(--occ[s[l] - 'a'] == 0)
                    distinct--;
        }
    }

    vector<vector<ll>> dp(n+1, vector<ll> (27, 0)), ps(n+2, vector<ll> (27, 0));
    ll ans = 0;
    for(int i = n-1; i >= 0; i--)
    {
        for(int j = 1; j <= 26; j++)
        {
            if(j == 1)
            {
                int fn = nxt[i][j];
                if(fn == -1) continue;
                if(fn != i)
                {
                    dp[i][j] += (ps[i+1][j] - ps[fn+2][j] + mod) % mod;
                    dp[i][j] %= mod;
                    ans += (ps[i+1][j] - ps[fn+2][j] + mod) % mod;
                    ans %= mod;
                } else
                {
                    dp[i][j] += dp[i+1][j];
                    dp[i][j] %= mod;
                    ans += dp[i+1][j];
                    ans %= mod;
                }
                dp[i][j] += (fn-i+1);
                dp[i][j] %= mod;
            } else
            {
                int st = nxt[i][j-1]+1;
                int fn = nxt[i][j];
                if(st == -1 || fn == -1) continue;
                dp[i][j] += (ps[st+1][j] - ps[fn+2][j] + mod) % mod;
                dp[i][j] %= mod;
                ans += (ps[st+1][j] - ps[fn+2][j] + mod) % mod;
                ans %= mod;
                dp[i][j] += (fn-st+1);
                dp[i][j] %= mod;
            }

            ps[i][j] = ps[i+1][j] + dp[i][j];
        }
    }

    cout << ans << "\n";
}
