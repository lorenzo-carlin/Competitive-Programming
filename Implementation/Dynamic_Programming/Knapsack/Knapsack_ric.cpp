#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, W;
const int MAXN = 105;
const int MAXW = 1e5+5;
ll p[MAXN];
ll w[MAXN];
ll memo[MAXN][MAXW];
bool vis[MAXN][MAXW];

ll solve(int ind, int curr)
{
    if(curr < 0) return -1e9;
    if(ind == N) return 0;
    if(curr == 0) return 0;
    
    if(vis[ind][curr]) return memo[ind][curr];
    vis[ind][curr] = true;

    return memo[ind][curr] = max(solve(ind+1, curr), solve(ind+1, curr-w[ind])+p[ind]);
}

int main()
{
    cin >> N >> W;
    for(int i = 0; i < N; ++i) cin >> w[i] >> p[i];

    cout << solve(0, W) << "\n";
}