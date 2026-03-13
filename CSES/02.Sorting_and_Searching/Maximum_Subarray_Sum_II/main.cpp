#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n, a, b; cin >> n >> a >> b;
    vector<ll> v(n);
    for(auto &i: v) cin >> i;
 
    vector<ll> ps;
    ps.push_back(0);
    for(int i = 0; i < n; ++i)
    {
        ps.push_back(ps.back() + v[i]);
    }
 
    priority_queue<pair<ll,ll>> pq;
    ll l = 0, r = 0, maxx = -1e18;
    for(l = 0; l < n; l++)
    {
        while(r < n && (r - l + 1) <= b)
        {
            pq.push({ps[r+1], r+1});
            r++;
        }
        while(!pq.empty() && pq.top().second - a < l)
        {
            pq.pop();
        }
        if(!pq.empty() && pq.top().second - a >= l)
        {
            maxx = max(maxx, ps[pq.top().second]-ps[l]);
        }
    }
    cout << maxx << "\n";
}
