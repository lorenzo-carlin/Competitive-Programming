#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S;
    cin >> N >> S;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) cin >> H[i];

    vector<vector<char>> pref(N + 1, vector<char>(S + 1, 0));
    vector<vector<char>> suff(N + 2, vector<char>(S + 1, 0));

    pref[0][0] = 1;
    for (int i = 0; i < N; ++i) {
        for (int s = 0; s <= S; ++s) {
            if (pref[i][s]) {
                pref[i + 1][s] = 1;
                if (s + H[i] <= S) pref[i + 1][s + H[i]] = 1;
            }
        }
    }

    suff[N + 1][0] = 1;
    for (int i = N; i >= 1; --i) {
        for (int s = 0; s <= S; ++s) {
            if (suff[i + 1][s]) {
                suff[i][s] = 1;
                if (s + H[i - 1] <= S) suff[i][s + H[i - 1]] = 1;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        bool possible = false;
        for (int a = 0; a <= S; ++a) {
            if (!pref[i][a]) continue;
            int b = S - a;
            if (b < 0 || b > S) continue;
            if (suff[i + 2][b]) { // salta il brick i
                possible = true;
                break;
            }
        }
        cout << (possible ? "NO" : "YES") << "\n";
    }
}

