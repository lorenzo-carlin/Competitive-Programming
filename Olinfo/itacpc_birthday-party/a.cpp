#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll NEG = (ll)-4e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<ll>> V(m);
    for (int i = 0; i < n; ++i) {
        ll a; cin >> a;
        V[a % m].push_back(a);
    }

    // Ordina decrescente e costruisci prefissi
    vector<vector<ll>> pref(m);
    for (int r = 0; r < m; ++r) {
        auto &vec = V[r];
        sort(vec.begin(), vec.end(), greater<ll>());
        pref[r].assign(vec.size() + 1, 0); // pref[0] = 0
        for (size_t i = 0; i < vec.size(); ++i)
            pref[r][i+1] = pref[r][i] + vec[i];
    }

    // Per ogni classe r, calcola best[rem] = massimo prefisso tra t con t % m == rem
    vector<vector<ll>> best(m, vector<ll>(m, NEG));
    for (int r = 0; r < m; ++r) {
        int sz = (int)pref[r].size() - 1;
        best[r][0] = 0; // prendere 0 elementi è sempre possibile con somma 0
        for (int t = 1; t <= sz; ++t) {
            int rem = t % m;
            best[r][rem] = max(best[r][rem], pref[r][t]);
        }
        // best[r][0] già è almeno 0; ma se esistono t>0 con t%m==0 e pref>0, best[r][0] verrà aggiornato
    }

    // DP: dp[count_mod][sum_mod] = massimo somma
    vector<vector<ll>> dp(m, vector<ll>(m, NEG));
    dp[0][0] = 0;

    for (int r = 0; r < m; ++r) {
        vector<vector<ll>> ndp(m, vector<ll>(m, NEG));
        for (int cm = 0; cm < m; ++cm) {
            for (int sm = 0; sm < m; ++sm) {
                if (dp[cm][sm] == NEG) continue;
                // per ogni opzione di questa classe
                for (int tmod = 0; tmod < m; ++tmod) {
                    if (best[r][tmod] == NEG) continue;
                    int ncm = (cm + tmod) % m;
                    int nsm = (sm + (ll)tmod * r % m) % m;
                    ndp[ncm][nsm] = max(ndp[ncm][nsm], dp[cm][sm] + best[r][tmod]);
                }
            }
        }
        dp.swap(ndp);
    }

    cout << max(0LL, dp[0][0]) << "\n";
    return 0;
}

