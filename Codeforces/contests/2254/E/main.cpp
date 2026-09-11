#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<ll> v(n);
    multiset<ll> ms;
    ll delta = 0;
    ll mn_pos = 1e10;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        ms.insert(v[i]);
        delta += v[i];
        if(v[i] > 0) {
            mn_pos = min(mn_pos, v[i]);
        }
    }

    if(delta <= 0) {
        cout << -1 << "\n";
        return;
    }

    vector<ll> ans(n);
    ans[0] = mn_pos;
    ms.erase(ms.find(mn_pos));

    for(int i = 1; i < n; i++) {
        auto it = ms.upper_bound(-ans[i-1]);
        ans[i] = ans[i-1] + (*it);
        ms.erase(it);
    }

    for(ll el: ans) {
        cout << el << " ";
    }
    cout << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}