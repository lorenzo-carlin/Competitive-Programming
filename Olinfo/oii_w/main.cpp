#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll estrai(int n, ll k, vector<int> a, vector<int> q) {

  priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;

  ll mandatory = 0;
  ll actual = 0;
  ll minutes = 0;
  ll ans = 2e18;

  for(int i = 0; i < n; i++) {
    mandatory += q[i];
    
    if(a[i] > 1) {
      pq.push({q[i], a[i]-1});
      actual += 1LL * (a[i]-1) * q[i];
      minutes += (a[i]-1);
    }

    ll required = max(0LL, k-mandatory);

    while(!pq.empty()) {

      ll b = pq.top().first;
      ll c = pq.top().second;
      
      if(actual - b < required) {
        break;
      }

      pq.pop();
      ll extra = actual - required;
      ll toRemove = min(c, extra / b);

      if(toRemove >= c) {
        actual -= (b*c);
        minutes -= c;
      } else {
        actual -= (b*toRemove);
        minutes -= toRemove;
        pq.push({b, c-toRemove});
        break;
      }
    }

    // cout << minutes << "\n";
    
    if(actual >= required) {
      ans = min(ans, (ll)(i+1) + minutes);
    }
  }

  return ans;
}
