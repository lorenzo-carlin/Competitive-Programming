#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int INF = 1e9;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t; cin >> t;
    for(int cas = 1; cas <= t; ++cas)
    {
        int n, m; cin >> n >> m;
        vector<int> h(n), d(n);
        for(auto &i: h) cin >> i;
        for(auto &i: d) cin >> i;

        ll ans = INF;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                ll sol = h[0]+d[0]*i;
                ll cur = h[0]+d[0]*i;
                for(int x = 1; x < n; ++x)
                {
                    if(cur >= (h[x]+d[x]*(m-1)))
                    {
                        sol += abs(cur - (h[x]+d[x]*(m-1)));
                        cur = h[x]+d[x]*(m-1);
                    } else if(cur <= h[x])
                    {
                        sol += abs(cur - (h[x]));
                        cur = h[x];
                    } else
                    {
                        cur -= h[x];
                        ll tmp = cur/d[x];
                        ll sup = abs(cur - (h[x]+d[x]*(tmp+1)));
                        ll inf = abs(cur - (h[x]+d[x]*(tmp)));
                        cur += h[x];
                        if(abs(cur - sup) < abs(cur - inf))
                        {
                            sol += abs(cur - sup);
                            cur = sup;
                        } else
                        {
                            sol += abs(cur - inf);
                            cur = inf;
                        }
                    }

                }

                ans = min(ans, sol);
            }
        }
        
        cout << "Case #" << cas << ": " << ans << "\n";
    }
}