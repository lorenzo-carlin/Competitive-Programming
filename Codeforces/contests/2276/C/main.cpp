#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int &i: v) cin >> i;

    vector<ll> ps(n+1, 0);
    for(int i = 1; i <= n; i++) {
        ps[i] = ((ps[i-1] + v[i-1]) % k);
    }

    ll ans = 0;
    vector<int> occ(k, 0);
    for(int r = k+1; r <= n; r++) {
        occ[ps[r]]++;
    }

    int r = k+1;
    for(int l = 0; l <= n-k && r <= n; l++, r++) {
        ans += (occ[ps[l]]);
        if(l < n-k) {
            occ[ps[r]]--;
        }
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}