#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    vector<int> zero, due, cinque, sei;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') zero.push_back(i);
        if(s[i] == '2') due.push_back(i);
        if(s[i] == '5') cinque.push_back(i);
        if(s[i] == '6') sei.push_back(i);
    }

    vector<ll> D1(n + 2, 0);
    vector<ll> D_const(n + 2, 0);
    vector<ll> D_coeff(n + 2, 0);

    auto add_const = [&](vector<ll>& D, int L, int R, ll val) {
        if(L <= R) {
            D[L] += val;
            D[R + 1] -= val;
        }
    };

    for(int l = 0; l < n; l++) {
        auto it1 = lower_bound(begin(due), end(due), l);
        if(it1 == end(due)) continue;
        int d1 = *it1;

        auto it2 = upper_bound(begin(zero), end(zero), d1);
        if(it2 == end(zero)) continue;
        int d2 = *it2;

        auto it3 = upper_bound(begin(due), end(due), d2);
        if(it3 == end(due)) continue;
        int d3 = *it3;

        auto it5 = upper_bound(begin(cinque), end(cinque), d3);
        if(it5 == end(cinque)) continue;

        int A = *it5;
        
        auto it6 = upper_bound(begin(sei), end(sei), d3);
        int B = (it6 == end(sei)) ? n - 1 : min(n - 1, *it6 - 1);

        if(A <= B) {
            add_const(D1, l, A, B - A + 1);

            if(A + 1 <= B) {
                add_const(D_const, A + 1, B, B + 1);
                add_const(D_coeff, A + 1, B, -1);
            }
        }
    }

    ll cur1 = 0, cur_const = 0, cur_coeff = 0;
    for(int i = 0; i < n; i++) {
        cur1 += D1[i];
        cur_const += D_const[i];
        cur_coeff += D_coeff[i];

        ll bad_cnt = cur1 + cur_const + cur_coeff * i;
        ll total_subs = 1LL * (i + 1) * (n - i);

        cout << total_subs - bad_cnt << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}