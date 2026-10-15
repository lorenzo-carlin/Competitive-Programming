#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s; cin >> s;
    vector<int> compress;
    int cnt = 0;
    for(int i = 0; i < s.size()-1; i++) {
        cnt++;
        if(s[i] != s[i+1]) {
            compress.push_back(cnt);
            cnt = 0;
        }
    }
    cnt++;
    compress.push_back(cnt);

    if(compress.front() == 1) {
        compress.erase(compress.begin());
    }

    if(compress.back() == 1) {
        compress.pop_back();
    }

    bool one = false, three = false;

    int ans = 1;
    for(int el: compress) {
        if(el == 1) one = true;
        if(el >= 3) three = true;
    }

    if(one) ans++;
    if(three) ans++;

    cout << ans << "\n";

}

int main() {
    int t; cin >> t;
    while(t--) solve();
}