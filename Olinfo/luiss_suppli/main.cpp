#include <iostream>
#include <vector>
using namespace std;

int MAX = 100;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<bool> dp(MAX, false);
    vector<int> conf(n);

    for(auto &i:conf) cin >> i;

    dp[0] = true;
    for(int i = 1; i < MAX; ++i)
    {
        for(int j = 0; j < conf.size(); ++j)
        {
            if(i >= conf[j])
            {
                if(dp[i-conf[j]])
                {
                    dp[i] = true;
                    break;
                }
            }
        }
    }

    for(int i = MAX-1; i >= 0; --i)
    {
        if(!dp[i])
        {
            cout << i;
            return 0;
        }
    }
}