#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    array<int,3> ar = {a, b, c};
    sort(begin(ar), end(ar));

    int cnt = 0;
    while(ar[0] != ar[1] && ar[1] != ar[2]) {
        cnt++;
        ar[2]--;
        ar[0]++;
        sort(begin(ar), end(ar));
    }

    cout << cnt << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}