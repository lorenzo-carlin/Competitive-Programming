#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> v(n);
    for(auto &i: v) cin >> i;

    ll ans = 0;
    for(int i = k-1; i < n-k+1; i++) {
        ans += v[i];
    }
    for(int i = 0; i < min(k-1, n-k+1); i++) {
        ans += max(v[i], v[n-i-1]);
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}