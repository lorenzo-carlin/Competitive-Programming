#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for(int &i: v) cin >> i;

    vector<vector<int>> cycles(n);

    auto reduce = [&] (auto reduce, int val, int idx) -> void {
        if(cycles[idx].size() > 22) {
            return;
        }
        cycles[idx].push_back(val);
        if(val == 1) {
            return;
        }

        int nxt = 0;
        while(val > 0) {
            nxt += (val%10)*(val%10);
            val /= 10;
        }

        reduce(reduce, nxt, idx);
    };

    for(int i = 0; i < n; i++) {
        reduce(reduce, v[i], i);
    }

    auto inTune = [&] (int i, int j) -> bool {
        if(cycles[i].back() == 1 && cycles[j].back() == 1) {
            return true;
        }

        if(cycles[i].size() != cycles[j].size()) {
            return false;
        }

        for(int k = 0; k < cycles[i].size(); k++) {
            if(cycles[i][k] == cycles[j][k]) {
                return true;
            }
        }

        return false;
    };
    
    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(inTune(i, j)) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
}

int main() {

    int t; cin >> t;
    while(t--) solve();

}