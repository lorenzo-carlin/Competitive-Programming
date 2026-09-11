#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool possible(int n, vector<pair<int,int>> v)
{
    int x = v[n].first, y = v[n].second;
    for(int i = 0; i < n; ++i)
    {
        if((x < v[i].first && y > v[i].second) || (x > v[i].first && y < v[i].second)) return false;
    }
    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for(int x = 1; x <= t; ++x)
    {
        int n; cin >> n;
        vector<pair<int,int>> v(n);
        for(auto &i: v) cin >> i.first >> i.second;

        int sol = 0, i = 0;
        int l = 0, r = n-1;
        while(l < r-1)
        {
            int m = (l + r) / 2;
            if(possible(m, v)) l = m;
            else r = m;
        }
        if(possible(r, v)) sol = r;
        else sol = l;

        cout << "Case #" << x << ": " << sol+1 << "\n";
    }
}