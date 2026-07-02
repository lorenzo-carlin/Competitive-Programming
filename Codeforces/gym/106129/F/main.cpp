#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<vector<int>> a(n + 1, vector<int>(m + 1));

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < m; ++j) {
            a[i + 1][j + 1] = s[i][j] == '#' ? 1 : 0; 
        }
    }

    auto pref = a;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            pref[i][j] = a[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }

    auto Get = [&](int x1, int y1, int x2, int y2) {
        return pref[y2][x2] - pref[y2][x1 - 1] - pref[y1 - 1][x2] + pref[y1 - 1][x1 - 1];
    };

    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1));
    auto Good = [&](int y, int x, int len) -> bool {
        int x2 = x + len - 1;
        int y2 = y + len - 1;
        if (y2 > n || x2 > m) {
            return false;
        }
        
        if (Get(x, y, x2, y2) == (y2 - y + 1) * (x2 - x + 1)) {
            for (int i = y; i <= y2; ++i) {
                for (int j = x; j <= x2; ++j) {
                    if (vis[i][j]) {
                        return false;
                    } else {
                        vis[i][j] = true;
                    }
                }
            }
            return true;
        } else {
            return false;
        }
    };

    auto init = [&]() {
        for (int row = 1; row <= n; ++row) {
            for (int col = 1; col <= m; ++col) {
                vis[row][col] = false;
            }
        }
    };

    auto work = [&](int div) -> bool {
        init();
        for (int row = 1; row <= n; ++row) {
            for (int col = 1; col <= m; ++col) {
                if (a[row][col] && !vis[row][col]) { // mark
                    // cerr << "TRY " << row << ", " << col << endl;
                    if (!Good(row, col, div)) {
                        return false;
                    }
                }
            }
        }

        return true;
    };

    int N = max(n, m);
    int ans = 1;
    vector<bool> possible(N + 1, true);
    for (int d = 2; d <= N; ++d) {
        if (!possible[d]) {
            continue;
        }
        if (work(d)) {
            ans = max(ans, d);
        } else {
            for (int mul = d; mul <= N; mul += d) {
                possible[mul] = false;
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}