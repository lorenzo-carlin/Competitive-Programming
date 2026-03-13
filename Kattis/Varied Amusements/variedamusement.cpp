#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 50;
int dp[3][MAX];
int mod = 1e9+7;
int n, a, b, c;

ll solve(char gst, int pos)
{
    // memoization
    if(gst == 'a' && dp[0][pos]!=-1)
    {
        return dp[0][pos];
    }
    if(gst == 'b' && dp[1][pos]!=-1)
    {
        return dp[1][pos];
    }
    if(gst == 'c' && dp[2][pos]!=-1)
    {
        return dp[2][pos];
    }


    // casi base
    if(pos == n-1)
    {
        if(gst == 'a')
        {
            return a;
        } else if(gst == 'b')
        {
            return b;
        } else
        {
            return c;
        }
    }

    // algoritmo risolutivo
    if(gst == 'a')
    {
        dp[0][pos] = (a*(solve('b', pos+1)+solve('c', pos+1)))%mod;
        return dp[0][pos];
    } else if(gst == 'b')
    {
        dp[1][pos] = (b*(solve('a', pos+1)+solve('c', pos+1)))%mod;
        return dp[1][pos];
    } else
    {
        dp[2][pos] = (c*(solve('a', pos+1)+solve('b', pos+1)))%mod;
        return dp[2][pos];
    }
}

int main()
{
    cin >> n >> a >> b >> c;
    for(int i = 0; i < n; ++i)
    {
        dp[0][i] = -1;
        dp[1][i] = -1;
        dp[2][i] = -1;
    }
    ll ans = (solve('a', 0)+solve('b', 0)+solve('c', 0))%mod;
    cout << ans << "\n";
}