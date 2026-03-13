#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
bool vis[MAX][MAX];
char mp[MAX][MAX];
int n, m;

void dfs(int i, int j)
{
    if(i >= n || i < 0 || j >= m || j < 0 || vis[i][j] || mp[i][j] == '#')
    {
        return;
    }

    vis[i][j] = true;
    dfs(i-1, j);
    dfs(i, j-1);
    dfs(i+1, j);
    dfs(i, j+1);
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> mp[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(mp[i][j] == '.' && !vis[i][j])
            {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans;
}