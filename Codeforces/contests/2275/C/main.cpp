#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for(ll &i: a) cin >> i;

    ll ans = 0;

    map<ll,ll> mpP;
    for(int i = 0; i < n-4; i+=2) {
        ll cur = a[i]+a[i+2]-a[i+4];
        ans += mpP[cur];
        if(i >= 2 && (a[i-2] + a[i] - a[i+2]) == cur) {
            ans--;
        }
        if(i >= 4 && (a[i-4] + a[i-2] - a[i]) == cur) {
            ans--;
        }
        mpP[cur]++;
    }

    map<ll,ll> mpD;
    for(int i = 1; i < n-4; i+=2) {
        ll cur = a[i]+a[i+2]-a[i+4];
        ans += mpD[cur];
        if(i >= 2 && (a[i-2] + a[i] - a[i+2]) == cur) {
            ans--;
        }
        if(i >= 4 && (a[i-4] + a[i-2] - a[i]) == cur) {
            ans--;
        }
        mpD[cur]++;

        ans += mpP[cur];
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}