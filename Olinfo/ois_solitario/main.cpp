#include <bits/stdc++.h>
using namespace std;

int r, c, cnt = 0, ans = 0;
int mat[10][10];

bool possplace(int x, int y)
{
    if(x>=2 && mat[x-2][y]==1 && mat[x-1][y]==1) return false;
    if(y>=2 && mat[x][y-2]==1 && mat[x][y-1]==1) return false;
    if(x>=2 && y>=2 && mat[x-2][y-2]==1 && mat[x-1][y-1]==1) return false;
    if(x>=2 && y<c-2 && mat[x-2][y+2]==1 && mat[x-1][y+1]==1) return false;
    return true;
}

void solve(int x, int y)
{
    int res_mx = c * (r - x - 1) + (c - y - 1) + 1;
    if(cnt + res_mx <= ans) return;
    if(possplace(x,y))
    {
        ++cnt;
        mat[x][y] = 1;
        if(x == r-1 && y == c-1)
        {
            ans = max(cnt, ans);
        } else if(y != c-1)
        {
            solve(x,y+1);
        } else
        {
            solve(x+1,0);
        }
        --cnt;
    }
    mat[x][y] = 0;
    if(x == r-1 && y == c-1)
    {
        ans = max(cnt, ans);
    } else if(y != c-1)
    {
        solve(x,y+1);
    } else
    {
        solve(x+1,0);
    }
}

int main()
{
    cin >> r >> c;
    solve(0,0);
    cout << ans << "\n";
}