#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
char mat[MAX][MAX];
bool vis[MAX][MAX];
int r, c;
bool cond;

void dfs(int x, int y)
{
    if(x < 0 || x == r || y < 0 || y == c || (mat[x][y] == '#') || vis[x][y])
    {
        return;
    }

    vis[x][y] = true;

    if(mat[x][y] == '@')
    {
        cond = true;
    }

    dfs(x-1, y);
    dfs(x, y-1);
    dfs(x+1, y);
    dfs(x, y+1);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> r >> c;

    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            cin >> mat[i][j];
            vis[i][j] = false;
        }
    }

    int ans = 0;
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            if(mat[i][j]!='#' && !vis[i][j])
            {
                cond = false;
                dfs(i, j);
                if(!cond)
                {
                    ans++;
                }
            }
        }
    }

    cout << ans << "\n";
}