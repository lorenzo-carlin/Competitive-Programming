#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU
{
    int n;
    vector<int> par;
    vector<pair<int,int>> win;

    DSU() {}
    DSU(int _n) : n(_n)
    {
        par.resize(n);
        win.resize(n);

        iota(begin(par), end(par), 0);
        for(int i = 0; i < n; i++) win[i] = {i, i};
    }

    int find(int a)
    {
        return (par[a] == a) ? (par[a]) : (par[a] = find(par[a]));
    }

    pair<int,int> window(int a)
    {
        int A = find(a);
        return win[A];
    }

    void merge(int a, int b)
    {
        int A = find(a);
        int B = find(b);

        par[B] = A;
        win[A].first = min(win[A].first, win[B].first);
        win[A].second = max(win[A].second, win[B].second);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<pair<ll,int>> v(n);
    vector<bool> vis(n, false);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(begin(v), end(v));

    DSU dsu = DSU(n);

    ll ans = 0;
    for(int i = 0; i < n-1; i++)
    {
        int j = v[i].second;
        vis[j] = true;
        if(j < n-1 && vis[j+1]) dsu.merge(j, j+1);
        if(j > 0 && vis[j-1]) dsu.merge(j, j-1);
        auto [l, r] = dsu.window(j);
        if(r == n-1) r = 1e9;
        if(l == 0) l = -1e9;
        ans += min(j-l+1, r-j+1);
    }

    cout << ans << "\n";
}
