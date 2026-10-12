#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, k; cin >> n >> k;

    ll sum = 0, mn = 1e18;
    vector<array<ll,3>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        sum += (v[i][0] + v[i][1] + v[i][2]);
        mn = min(mn, v[i][0] + v[i][1] + v[i][2]);
    }

    auto valid = [&] (ll q) -> bool {
        ll needed = 0;
        ll a, b, c;
        for(int i = 0; i < n; i++) {
            a = v[i][0];
            b = v[i][1];
            c = v[i][2];

            if(a+b+c >= q) {
                continue;
            }

            if(c > b && b > a) {
                needed += max(min(q+2-a-3*b+c, q+2-3*a+b-c), 0LL);
            } else if((c == b && b > a) || (c > b && b == a)) {
                needed += max((2+q-a-b-c), 0LL);
            } else if(c == b && b == a) {
                return false;
            } else {
                needed += max((q-a-b-c), 0LL);
            }
        }

        return (needed <= k);
    };

    ll st = mn;
    ll fn = ((sum + k) / n) + 5;

    ll lastValid = -1;
    while(st < fn) {
        ll m = (st + fn) / 2;
        if(valid(m)) {
            lastValid = m;
            st = m+1;
        } else {
            fn = m-1;
        }
    }
    if(valid(st)) {
        lastValid = st;
    }

    cout << lastValid << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}