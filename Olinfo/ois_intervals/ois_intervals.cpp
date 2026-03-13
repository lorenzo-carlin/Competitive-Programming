#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for(auto &i: v) cin >> i.first >> i.second;
    sort(begin(v), end(v));

    map<int,set<int>> st, fn;

    for(int i = 0; i < n; ++i)
    {
        int s = v[i].first;
        int f = v[i].second;

        if(!fn[s].empty())
        {
            int vecchio = *fn[s].begin();
            fn[s].erase(fn[s].begin());
            fn[f].insert(vecchio);
        } else
        {
            st[s].insert(i);
            fn[f].insert(i);
        }
    }

    set<int> sol;
    for(auto el: fn)
    {
        for(auto i: el.second)
        {
            sol.insert(i);
        }
    }

    cout << sol.size() << "\n";
}