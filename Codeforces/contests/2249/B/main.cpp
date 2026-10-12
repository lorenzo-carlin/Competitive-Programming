#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll mod = 998244353;

void solve() {

    int n; cin >> n;
    vector<int> a(n-1);
    for(int &i: a) cin >> i;

    if(n == 2 && a[0] != 1) {
        cout << 0 << "\n";
        return;
    }

    for(int i = 0; i < n-1; i++) {
        if(a[i] == n) {
            cout << 0 << "\n";
            return;
        }
    }

    vector<bool> pre(n-1, false); pre.front() = true;
    vector<bool> suf(n-1, false); suf.back() = true;
    for(int i = 1; i < n-1; i++) {
        pre[i] = (pre[i-1] && (a[i] >= a[i-1]));
    }
    for(int i = n-3; i >= 0; i--) {
        suf[i] = (suf[i+1] && (a[i] >= a[i+1]));
    }

    bool exit = false;

    auto compute = [&] (int idx) -> ll {

        deque<int> l, r;
        for(int i = 0; i < idx; i++) {
            l.push_back(a[i]);
        }
        for(int i = n-2; i >= idx; i--) {
            r.push_back(a[i]);
        }

        vector<int> m;
        for(int i = 0; i < n-1; i++) {
            if(l.empty()) {
                m.push_back(r.front());
                r.pop_front();
            } else if(r.empty()) {
                m.push_back(l.front());
                l.pop_front();
            } else if(l.front() < r.front()) {
                m.push_back(l.front());
                l.pop_front();
            } else if(l.front() > r.front()){
                m.push_back(r.front());
                r.pop_front();
            } else {
                exit = true;
                return 0;
            }
        }

        ll ans = 1;
        vector<bool> selected(n+1, false);
        for(int i = 0; i < n-1; i++) {
            if(selected[m[i]]) {
                ans *= (m[i] - i);
                ans %= mod;
            } else {
                selected[m[i]] = true;
            }
        }

        //cout << "compute(" << idx << "): " << ans << "\n";
        return ans;

    };

    ll ans = 0;

    if(pre.back()) {
        ans += compute(n-1);
        ans %= mod;
    }

    if(suf.front()) {
        ans += compute(0);
        ans %= mod;
    }

    for(int i = 1; i < n-1; i++) {
        if(pre[i-1] && suf[i] && (a[i] != a[i-1])) {
            ans += compute(i);
            ans %= mod;
        }
    }

    if(exit) {
        cout << 0 << "\n";
        return;
    }

    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}