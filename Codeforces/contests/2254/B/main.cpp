#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int len = 1;
    for(int i = 0; i < n-1; i++) {
        if(s[i] != s[i+1]) {
            len++;
        }
    }

    int mn = len;
    for(int i = 1; i < n-1; i++) {
        if(s[i-1] == s[i+1] && s[i-1] != s[i]) {
            mn = min(mn, len-2);
        }
        if(s[i-1] != s[i] && s[i] != s[i+1]) {
            mn = min(mn, len-1);
        }
    }

    cout << mn << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}