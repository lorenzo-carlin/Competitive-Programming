#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for(auto &i:v) cin >> i;

    /*
    Soluzione iterativa: per ogni posizione dell'array calcolo il subarray di somma massima che termina in quella posizione.
    Si calcola tenendo in conto o solo l'elemento in quella posizione, o quell'elemento più il subarray massimo di posizione-1.
    */
    vector<int> dp(n,0);
    dp[0] = v[0];
    int ans = 0;
    for(int i = 1; i < n; ++i)
    {
        dp[i] = max(v[i], dp[i-1]+v[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
}