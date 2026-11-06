#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int q; cin >> q;
    vector<ll> ms;
    vector<ll> ps(1, 0);
    ll size = 0;

    streamsize ssize = cout.precision();
    cout << fixed;
    cout.precision(10);

    auto mean = [&] (int idx) -> double {
        if(size == 1) {
            return ((double)ms.front());
        }
        if(idx == size-1) {
            return (((double)ps.back())/((double)size));
        }
        return (((double)ps[idx+1] + (double)ms.back()) / ((double) (idx+2.0)));
    };

    int curMin = 0;
    
    while(q--) {
        int t, x; cin >> t;
        if(t == 1) {
            cin >> x;
            ms.push_back(x);
            ps.push_back(ps.back() + x);
            size++;
        } else {
            while(mean(curMin) > mean(curMin+1)) {
                curMin++;
            }
            cout << ((double)ms.back() - (double)mean(curMin)) << "\n";
        }
    }
}