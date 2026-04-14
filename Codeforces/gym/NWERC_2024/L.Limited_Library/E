#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> a(n), b(m);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    sort(b.rbegin(), b.rend());
    sort(a.rbegin(), a.rend());
    // is always convenient to fit the thing with the big one
    auto possible = [&](int k) -> bool {
        vector<int> cap(n, x);
        for (int i = 0; i < k; ++i) {
            cap[n - i - 1] = y;
        }

        for (int i = 0, j = 0; i < m; ++i) {
            if (j == n) {
                return false;
            }
            // cerr << "Shelf " << j << " cap " << cap[j] << " heigth " << a[j] << " book " << b[i] << endl;
            if (a[j] >= b[i]) {
                --cap[j];
            } else {
                return false;
            }
            if (cap[j] == 0) { // use the next shelf
                ++j;
            }
        }

        return true;
    };


    int low = 0, high = n;
    int ans = -1;
    while (low <= high) {
        // cerr << low << " " << high << endl;
        int mid = (low + high) >> 1;
        if (possible(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (ans == -1) {
        cout << "impossible\n";
    } else {
        cout << ans << "\n";
    }
    return 0;    
}