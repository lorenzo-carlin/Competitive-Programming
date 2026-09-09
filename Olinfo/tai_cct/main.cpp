#include <bits/stdc++.h>
using namespace std;

int n, k;

int solve(int ind, int car, vector<int> &v, vector<int> &c, vector<vector<int>> &dp)
{
    if(ind == n) return 0;
    if(dp[ind][car] != -1) return dp[ind][car];

    int mn = 1e9;
    mn = min(mn, solve(ind+1, min(k, car+c[ind]), v, c, dp)+v[ind]);
    if(car == k) mn = min(mn, solve(ind+1, 0, v, c, dp));

    dp[ind][car] = mn;
    return dp[ind][car];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    vector<int> v(n), c(n);
    for(auto &i: v) cin >> i;
    for(auto &i: c) cin >> i;

    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    int sol = solve(0, 0, v, c, dp);
    cout << sol << "\n";
}