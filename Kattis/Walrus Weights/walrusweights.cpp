#include <bits/stdc++.h>
using namespace std;

int g = 1000;

int main()
{
    int n; cin >> n;
    bitset<2000> dp(false);
    vector<int> v(n);
    for(auto &i:v) cin >> i;
    dp[0] = true;
    for(auto c:v)
    {
        for(int i = 2000; i >= 0; --i)
        {
            if(dp[i] && i+c <= 2000)
            {
                dp[i+c] = true;
            }
        }
    }

    int l = 1000, r = 1000;
    while(true)
    {
        if(dp[r])
        {
            cout << r << endl;
            break;
        } else if(dp[l])
        {
            cout << l << endl;
            break;
        }
        l--;
        r++;
    }


}