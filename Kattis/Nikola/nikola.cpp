#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 1000;
vector<int> cost;
bool vis[MAX][MAX];
int dp[MAX][MAX];
int n;
int INF = 1e6;
set<pair<int,int>> s;

int solve(int pos, int salto)
{
    if(vis[pos][salto])         // posizione e salto da fare
    {
        return dp[pos][salto];
    }
    if(pos == n-1)            // se sono arrivato alla fine
    {
        return 0;
    }
    vis[pos][salto] = true;
    dp[pos][salto] = INT_MAX;
    if(pos+salto < n)       // se posso saltare in avanti
    {
        auto it = s.find({pos,pos+salto});
        if(it == s.end())
        {
            s.insert({pos,pos+salto});
            dp[pos][salto] = min(dp[pos][salto], solve(pos+salto, salto+1)+cost[pos+salto]);
        }
    }
    if(pos-1 > 0)       // se posso saltare all'indietro
    {
        auto it = s.find({pos,pos-salto});
        if(it == s.end())
        {
            s.insert({pos,pos-salto});
            dp[pos][salto] = min(dp[pos][salto], solve(pos-1, 1)+cost[pos-1]);
        }
    }
    return dp[pos][salto];
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int t; cin >> t;
        cost.push_back(t);
        for(int j = 0; j < n; ++j)
        {
            vis[i][j] = false;
        }
    }
    ll ans = solve(0, 1);
    cout << ans;
}