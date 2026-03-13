#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

typedef long long i64;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    i64 k;
    cin >> n >> k;
    string s;
    cin >> s;

    auto Even = [&]() {
        for (i64 j = 0; j < k; ++j) {
            if (count(s.begin(), s.end(), s[0]) == n) {
                break;
            }
            string m = s + s;
            string t = "";
            for (int i = 0; i < int(m.size()); i += 2) {
                t.push_back(m[i]);
                if (int(t.size()) == n) {
                    break;
                }
            }
            s = t;
        }

        cout << s << endl;
        exit(0);
    };

    auto Odd = [&]() {
        vector<int> g(n);

        auto createGraph = [&]() {
            int cnt = 1;
            for (int i = 2; i < n; i += 2) {
                g[i] = cnt;
                ++cnt;
            }

            for (int i = 1; i < n; i += 2) {
                g[i] = cnt;
                ++cnt;
            }
        };

        createGraph();
        // for (int i = 1; i < n; ++i) {
        //     cerr << "I " << i << " ==> " << g[i] << endl;
        // }
        // return;

        vector<bool> vis(n);
        vector<int> nodes;
        auto dfs = [&](auto &&self, int node) -> void {
            if (vis[node]) {
                return;
            }
            vis[node] = true;
            nodes.push_back(node);
            self(self, g[node]);
        };

        string ans(n, s[0]);

        for (int i = 1; i < n; ++i) {
            if (vis[i]) {
                continue;
            }
            nodes.clear();
            dfs(dfs, i);
            int sz = nodes.size();
            for (int i = 0; i < sz; ++i) {
                // int pos = nodes[i];
                // cerr << s[nodes[i]] << " put into " << nodes[(i + k - 1) % sz] << endl;
                ans[nodes[(i + k) % sz]] = s[nodes[i]];
                // ++cnt;
            }
        }

        cout << ans << "\n";
    };

    if (n % 2 == 0) {
        Even();
    } else {
        Odd();
    }

    return 0;
}