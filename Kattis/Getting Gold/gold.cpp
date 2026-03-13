#include <bits/stdc++.h>
using namespace std;

const int MAX = 50;
char mat[MAX][MAX];
bool vis[MAX][MAX];
int r, c;
int st_x, st_y;
int cnt = 0;

void dfs(int x, int y)
{
    if(mat[x][y] == '#' || mat[x][y] == 'T' || vis[x][y])
        return;
    vis[x][y] = true;
    if(mat[x][y] == 'G')
        cnt++;
    if(mat[x+1][y] != 'T' && mat[x][y+1] != 'T' && mat[x-1][y] != 'T' && mat[x][y-1] != 'T')
    {
        dfs(x+1, y);
        dfs(x, y+1);
        dfs(x-1, y);
        dfs(x, y-1);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> c >> r;
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            cin >> mat[i][j];
            if(mat[i][j] == 'P')
            {
                st_x = i;
                st_y = j;
            }
            vis[i][j] = false;
        }
    }
    dfs(st_x, st_y);
    cout << cnt;
}