#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T; cin >> T;
    for(int i = 1; i <= T; ++i)
    {
        // N = nmr uova iniziali, K = numero di pesci per ogni gruppo
        LL N, K; cin >> N >> K;
        LL ans = 0;
        while(N > 0)
        {
            ans += N;
            N = (N / K);
        }
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}