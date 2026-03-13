#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define f first
#define s second

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<pair<pair<int,int>,int>> v(n);
    vector<int> ind;
    for(int i = 0; i < n; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        v[i] = {{a, a+c}, b};
        ind.push_back(a);
        ind.push_back(a+c);
    }

    sort(begin(ind), end(ind));
    ind.erase(unique(begin(ind), end(ind)), end(ind));

    for(auto &i : v)
    {
        i.f.f = lower_bound(begin(ind), end(ind), i.f.f) - begin(ind);
        i.f.s = lower_bound(begin(ind), end(ind), i.f.s) - begin(ind);
    }

    map<int,vector<pair<int,int>>> mp;
    for(auto el: v) mp[el.f.s].push_back({el.f.f, el.s});

    vector<int> dp;
    dp.push_back(0);
    for(int i = 1; i <= 2*n; ++i)
    {
        int mx = 0;
        mx = max(mx, dp[i-1]);
        for(auto el: mp[i]) mx = max(mx, dp[el.f]+el.s);
        dp.push_back(mx);
    }
    
    cout << dp.back() << "\n";
}