#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> g;
const int MAX = 1000;
int dp[MAX][MAX];
int n, m;

int mostra(int x, int y)
{
    // x: nr di visitatori mancanti
    // y: nr di guide mancanti
    if(x == 0)
    {
        return 0;
    }
    if(y == 0)
    {
        return x;
    } 
    if(dp[x-1][y-1] != -1)
    {
        return dp[x-1][y-1];
    } else
    {
        if(v[n-x] < g[m-y])
        {
            dp[x-1][y-1] = max(mostra(x-1,y-1)+2, mostra(x-1,y)+1);
            return dp[x-1][y-1];
        } else
        {
            dp[x-1][y-1] = max(mostra(x-1,y)+1, mostra(x,y-1));
            return dp[x-1][y-1];
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t; cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        cin >> n >> m;
        for(int j = 0; j < n; ++j)
        {
            int tmp; cin >> tmp;
            v.push_back(tmp);
        }
        for(int j = 0; j < m; ++j)
        {
            int tmp; cin >> tmp;
            g.push_back(tmp);
        }
        for(int j = 0; j < n; ++j)
        {
            for(int k = 0; k < m; ++k)
            {
                dp[j][k] = -1;
            }
        }
        int ans = mostra(n, m);
        cout << "Case #" << i << ": " << ans << endl;
        v.clear();
        g.clear();
    }
}