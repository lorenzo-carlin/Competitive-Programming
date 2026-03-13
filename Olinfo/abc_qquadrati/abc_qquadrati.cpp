#include <bits/stdc++.h>
using namespace std;

int MAX = 32768;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    vector<int> v = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196};

    vector<int> dp(MAX+1, 0); dp[0] = 1;
    for(int i = 1; i <= MAX; ++i)
    {
        for(int j = 0; j < 14; ++j)
        {
            if(i - v[j] >= 0) dp[i] += dp[i - v[j]];
        }
    }

    int n; cin >> n;
    while(n--)
    {
        int a; cin >> a;
        cout << dp[a] << " ";
    }
    cout << "\n";

}