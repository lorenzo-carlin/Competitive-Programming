#include <bits/stdc++.h>
using namespace std;
using ll = long long;

set<int> valid = {0, 3, 5, 6, 9, 10, 12, 15};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for(int &i: v) cin >> i;

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(valid.count(v[i])) {
            ans++;
        }
    }
    cout << ans << " ";
    while(q--) {
        int p, x; cin >> p >> x; p--;
        if(valid.count(v[p])) {
            ans--;
        }
        v[p] = x;
        if(valid.count(v[p])) {
            ans++;
        }
        cout << ans << " ";
    }
    cout << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}