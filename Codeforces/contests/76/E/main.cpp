#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll A = 0, B = 0, C = 0, D = 0;
    
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;

        A += (x*x);
        B += (y*y);
        C += x;
        D += y;
    }

    ll ans = n*A + n*B - C*C - D*D;
    cout << ans << "\n";
}