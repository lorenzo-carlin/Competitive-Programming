#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU
{
    int n;
    vector<int> par;

    DSU(int _n) : n(_n)
    {
        par.resize(n);
        iota(begin(par), end(par), 0);
    }

    int find(int a)
    {
        return (a == par[a]) ? (a) : (par[a] = find(par[a]));
    }

    bool merge(int a, int b)
    {
        int A = find(a);
        int B = find(b);

        if(A != B)
        {
            par[A] = B;
            return true;
        }
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k; cin >> n >> m >> k;
    vector<array<int,3>> edges(m);
    for(int i = 0, a, b, c; i < m; i++)
    {
        cin >> a >> b >> c;
        a--; b--;
        edges[i] = {c, a, b};
    }

    auto MST = [&] (ll lambda) -> pair<int,ll>
    {
        vector<array<ll,3>> E(m);
        for(int i = 0; i < m; i++)
        {
            ll w = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];
            if(u == 0 || v == 0) w += lambda;
            E[i] = {w, u, v};
        }
        sort(begin(E), end(E));

        DSU dsu = DSU(n);
        ll tot = 0;
        ll cnt = 0;
        int used = 0;
        for(auto &e: E)
        {
            if(dsu.merge(e[1], e[2]))
            {
                tot += e[0];
                used++;
                if(e[1] == 0 || e[2] == 0) cnt++;
            }
        }

        if(used != n-1)
        {
            return {-1, (ll)1e18};
        }

        return {cnt, tot};
    };

    ll l = -1e9, r = 1e9;
    while(l < r)
    {
        ll m = (l + r) / 2;
        auto [d, _] = MST(m);
        if(d >= k)
            l = m+1;
        else
            r = m;
    }

    ll ans = (ll)1e18;

    for(ll lambda: {l, l-1})
    {
        auto [d, tot] = MST(lambda);
        if(d == k)
            ans = min(ans, tot-lambda*k);
    }

    if(ans == (ll)1e18)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
}
