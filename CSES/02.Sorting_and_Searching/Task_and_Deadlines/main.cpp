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
    
    ll sol = 0, cur = 0;
    for(int i = 0; i < n; ++i)
    {
        cur += v[i].first;
        sol += (v[i].second - cur);
    }
 
    cout << sol << "\n";
}
