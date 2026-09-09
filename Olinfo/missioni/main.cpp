#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> dp;

int solve(int ind, int day, vector<pair<int,int>> &v)
{
    if(ind >= n) return 0;
    if(dp[ind][day] != -1) return dp[ind][day];
    int mx = 0;
    if(day+v[ind].first <= v[ind].second) mx = max(mx, solve(ind+1, day+v[ind].first, v)+1);
    mx = max(mx, solve(ind+1, day, v));
    dp[ind][day] = mx;
    return dp[ind][day];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    vector<pair<int,int>> v(n);
    for(auto &i: v) cin >> i.first >> i.second;
    dp.resize(n, vector<int>(365, -1));
    cout << solve(0, 0, v) << "\n";
}