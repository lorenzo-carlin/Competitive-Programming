#include <bits/stdc++.h>
using namespace std;

int n;
const int MAX = 2999;
double dp[MAX][MAX];

double solve(int ind, int heads, vector<double> &v)
{
    if(ind == n) return (heads > n/2 ? 1.0 : 0.0);
    if(dp[ind][heads] != -1.0) return dp[ind][heads];

    double sol = 0.0;
    
    // testa
    sol += solve(ind+1, heads+1, v)*v[ind];

    // croce (se posso)
    int rim = n - (ind+1);
    if(heads + rim > n / 2)
    {
        sol += solve(ind+1, heads, v)*(1-v[ind]);
    }

    dp[ind][heads] = sol;
    return sol;
}

int main()
{
    cin >> n;

    vector<double> v(n);
    for(double &i: v) cin >> i;

    fill(*dp, *dp+MAX*MAX, -1.0);

    double sol = solve(0, 0, v);
    cout << fixed << setprecision(10) << floor(sol*10000000000) / 10000000000 << "\n";
}
