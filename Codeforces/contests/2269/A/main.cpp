#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    ll ans = 0;
    ans += 2*(k-1) + pow(2, n-k+1);
    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}