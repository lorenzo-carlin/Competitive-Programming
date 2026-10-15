#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a, b; cin >> a >> b;
    if(a <= b) {
        cout << -1 << "\n";
    } else {
        cout << min(a-b, b) << "\n";
    }
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}