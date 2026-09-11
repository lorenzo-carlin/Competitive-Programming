#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    string s1; cin >> s1;
    string s2; cin >> s2;

    int p1 = 0, d1 = 0;
    int p2 = 0, d2 = 0;

    for(int i = 0; i < n; i++) {
        if(s1[i] == '1') {
            if(i & 1) {
                p1++;
            } else {
                d1++;
            }
        }
        if(s2[i] == '1') {
            if(i & 1) {
                p2++;
            } else {
                d2++;
            }
        }
    }

    cout << ((p1 == p2 && d1 == d2) ? ("YES") : ("NO")) << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}