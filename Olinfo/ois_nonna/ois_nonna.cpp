#include <bits/stdc++.h>
using namespace std;

const int MAX = 5005;
int n, m;

int solve(int i, int curr, vector<int> &v, vector<vector<int>> &dp)
{
    if(curr <= 0) return 0;
    if(i == n) return 1e9;
    if(dp[i][curr] != -1) return dp[i][curr];
    int sol = min(solve(i+1, curr-v[i], v, dp) + v[i], solve(i+1, curr, v, dp));
    dp[i][curr] = sol;
    return dp[i][curr];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> m;
    vector<int> v(n);
    for(auto &el: v) cin >> el;
    vector<vector<int>> dp(MAX, vector<int> (MAX, -1));

    cout << solve(0, m, v, dp) << "\n";
}
