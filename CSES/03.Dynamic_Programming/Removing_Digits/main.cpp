#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> dp(n+1, 1e6);
    dp[0] = 0;

    for(int i = 1; i <= n; ++i)
    {
        string s = to_string(i);
        for(auto el: s)
        {
            if(el != '0')
            {
                int tmp = el - '0';
                dp[i] = min(dp[i], dp[i-tmp]+1);
            }
        }
    }

    cout << dp[n] << "\n";
}