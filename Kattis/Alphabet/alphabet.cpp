#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> dp(50, -1);

int solve(int pos)
{
    // memoization
    if(dp[pos] != -1)
    {
        return dp[pos];
    }

    // casi base
    if(pos == s.size()-1)
    {
        int ans = 'z' - s[pos];
        dp[pos] = ans;
        return ans;
    }
    if(s[pos] == 'z')
    {
        dp[pos] = 0;
        return 0;
    }

    // algoritmo
    int mn = 1e8;
    for(int i = pos+1; i < s.size(); ++i)
    {
        if(s[i] > s[pos])
        {
            mn = min(mn, solve(i)+(s[i]-s[pos]-1));
        }
    }
    if(mn == 1e8)
    {
        mn = 'z' - s[pos];
    }
    dp[pos] = mn;
    return mn;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    int mn = 1000;
    int mn_ind = -1;
    for(int i = 0; i < s.size(); ++i)
    {
        mn = min(mn, solve(i)+(s[i]-'a'));
        mn_ind = i;
    }
    cout << mn << "\n";
}