#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int c, n; cin >> c >> n;
    vector<int> v(c);
    for(auto &i: v) cin >> i;

    int l = 0, r = 0, mn = 1e9;
    map<int,int> mp;
    set<int> s;
    for(; l < c; ++l)
    {
        while(r < c && s.size() < n)
        {
            mp[v[r]]++;
            if(mp[v[r]] == 1) s.insert(v[r]);
            r++;
        }
        if(s.size() == n) mn = min(mn, r - l);
        mp[v[l]]--;
        if(mp[v[l]] == 0) s.erase(v[l]);
    }
    cout << mn << "\n";
}