#include <bits/stdc++.h>
using namespace std;

const int MAXK = 1e5+1;
int dp[MAXK][2];

bool solve(int k, bool per, vector<int> &v)
{
    if(dp[k][per] != -1) return dp[k][per];
    for(auto i: v)
    {
        if(k - i >= 0 && solve(k-i, !per, v)==per)
        {
            dp[k][per] = per;
            return per;
        }
    }
    dp[k][per] = !per;
    return !per;
}

int main()
{
    int n, k; cin >> n >> k;

    vector<int> v(n);
    for(auto &i: v) cin >> i;

    fill(*dp, *dp+MAXK*2, -1);

    if(solve(k, true, v)) cout << "First\n";
    else cout << "Second\n";

}