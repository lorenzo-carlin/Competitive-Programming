#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, w; cin >> n >> w;
    priority_queue<pair<ll,ll>> q;

    for(int i = 0; i < n; ++i)
    {
        ll a, b; cin >> a >> b;
        q.push({a,b});
    }

    ll ans = 0;
    ll tot_grams = 0;
    while(!q.empty())
    {
        if(tot_grams + q.top().second <= w)
        {
            tot_grams += q.top().second;
            ans += (q.top().first * q.top().second);
            q.pop();
        } else
        {
            ll diff = w - tot_grams;
            tot_grams = w;
            ans += (q.top().first * diff);
            break;
        }
    }

    cout << ans << "\n";
}