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

        vector<int> prec(m), curr(m, INF);
        for(int j = 0; j < m; ++j)
        {
            curr[j] = h[0]+d[0]*j;
        }

        for(int i = 1; i < n; ++i)
        {
            swap(prec, curr);
            curr.assign(m, INF);
            for(int j = 0; j < m; ++j)
            {
                for(int tmp = 0; tmp < m; ++tmp)
                {
                    curr[j] = min(curr[j], prec[tmp] + abs((h[i]+d[i]*j)-(h[i-1]+d[i-1]*tmp)));
                }
            }
        }

        int sol = INF;
        for(int j = 0; j < m; ++j)
        {
            sol = min(sol, curr[j]);
        }
        
        cout << "Case #" << cas << ": " << sol << "\n";
    }
}