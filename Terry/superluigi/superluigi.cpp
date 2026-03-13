#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

/*
dp[i][j] = costo minimo per arrivare al livello j (< M) del palo i (< N)

*/

ll solve(int i, int j, int &n, int &m, vector<ll> &d, vector<ll> &h)
{
    if(i == 0) return 0;

    ll mn = INF;

    for(int tmp = 0; tmp < m; tmp++)
    {
        mn = min(mn, solve(i-1, tmp, n, m, d, h) + abs((h[i]+d[i]*tmp) - (h[i-1]+d[i-1]*tmp)));
    }

    return mn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t; cin >> t;
    for(int cas = 1; cas <= t; ++cas)
    {
        int n, m; cin >> n >> m;
        vector<ll> h(n), d(n);
        for(auto &i: h) cin >> i;
        for(auto &i: d) cin >> i;

        ll sol = INF;
        for(int tmp = 0; tmp < m; tmp++)
        {
            sol = min(sol, solve(n-1, tmp, n, m, d, h));
        }

        cout << "Case #" << cas << ": " << sol << "\n";
    }
    return 0;
}