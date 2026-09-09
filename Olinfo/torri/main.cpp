#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define f first
#define s second

int n;
vector<pair<int,int>> v;
int memo[1005][1005] {};

int solve(int last, int ind)
{
    if(ind == n) return 0;

    if(memo[last][ind] != 0) return memo[last][ind];

    int mn = 1e9;

    if(v[ind].f < last) mn = min(mn, solve(v[ind].f, ind+1));
    mn = min(mn, solve(last, ind+1)+v[ind].s);

    return memo[last][ind] = mn;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    v.resize(n);
    for(auto &el: v) cin >> el.first >> el.second;

    cout << solve(1001, 0) << "\n";
}