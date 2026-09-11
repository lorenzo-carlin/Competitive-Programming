#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n; cin >> n;
    string s1; cin >> s1;
    string s2; cin >> s2;

    ll p1 = 0, d1 = 0;
    ll p2 = 0, d2 = 0;

    vector<ll> pari1, dispari1;
    vector<ll> pari2, dispari2;

    for(ll i = 0; i < n; i++) {
        if(s1[i] == '1') {
            if(i & 1) {
                p1++;
                pari1.push_back(i);
            } else {
                d1++;
                dispari1.push_back(i);
            }
        }
        if(s2[i] == '1') {
            if(i & 1) {
                p2++;
                pari2.push_back(i);
            } else {
                d2++;
                dispari2.push_back(i);
            }
        }
    }

    if(p1 != p2 || d1 != d2) {
        cout << -1 << "\n";
        return;
    }

    ll cnt = 0;
    for(ll i = 0; i < pari2.size(); i++) {
        cnt += (abs(pari2[i]-pari1[i]))/2;
    }
    for(ll i = 0; i < dispari2.size(); i++) {
        cnt += (abs(dispari2[i]-dispari1[i]))/2;
    }

    cout << cnt << "\n";
}

int main() {
    ll t; cin >> t;
    while(t--) {
        solve();
    }
}