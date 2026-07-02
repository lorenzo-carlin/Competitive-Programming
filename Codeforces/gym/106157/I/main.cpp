#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using i64 = long long;

bool isPow(i64 x) {
    return (x & (x - 1)) == 0;
}

int main() {
    i64 n;
    cin >> n;
    
    auto get = [&](i64 x) {
        int cnt = 0;
        while (x) {
            x /= 2;
            ++cnt;
        }
        return cnt;
    };

    auto print = [&](i64 x) {
        if (x == 1) {
            cout << "1 bit\n";
        } else {
            cout << x << " bits\n";
        }
    };

    i64 ans = get(n);
    while (!isPow(ans)) {
        // cout << ans << "\n";
        ++ans;
    }

    print(ans);
    return 0;
}