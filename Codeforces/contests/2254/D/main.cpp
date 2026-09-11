#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<pair<ll,int>> b(n);
    map<ll, vector<int>> mp;

    for(int i = 0; i < n; i++) {
        cin >> b[i].first;
        b[i].second = i;
        mp[b[i].first].push_back(b[i].second);
    }

    if(mp.count(0) == 0) {
        cout << -1 << "\n";
        return;
    }

    ll sum = 0, mx = 0;
    vector<int> last;
    vector<ll> ans(n);
    auto it = mp.begin();
    last = (*it).second;
    it++;

    while(it != mp.end()) {
        ll k = ((*it).first - sum);

        if((k % last.size() != 0) || (k / last.size() <= mx)) {
            cout << -1 << "\n";
            return;
        }

        for(int el: last) {
            ans[el] = (k / last.size());
            mx = max(mx, ans[el]);
        }

        sum += k;
        last = (*it).second;

        it++;
    }

    for(int el: last) {
        ans[el] = mx+1;
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