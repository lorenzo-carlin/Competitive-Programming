#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, q; cin >> n >> q;
    vector<ll> a(n);
    for(ll &i: a) cin >> i;

    vector<ll> dp(n); dp[n-1] = a[n-1];
    vector<ll> mx(n); mx[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--) {
        dp[i] = max(a[i], a[i]+dp[i+1]);
        mx[i] = max(mx[i+1], dp[i]);
    }

    while(q--) {
        int a; cin >> a;
        cout << mx[a] << "\n";
    }
}