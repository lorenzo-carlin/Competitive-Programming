#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 10;

int main()
{
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);

    char mat[MAX][MAX];
    bool vis[MAX][MAX];

    pair<int,int> B, R;
    for(int i = 0; i < MAX; ++i)
    {
        for(int j = 0; j < MAX; ++j)
        {
            cin >> mat[i][j];
            if(mat[i][j] == 'B') B = {i, j};
            if(mat[i][j] == 'R') R = {i, j};
            vis[i][j] = false;
        }
    }

    queue<pair<int,pair<int,int>>> q;
    q.push({-0, B});
    vis[B.first][B.second] = true;
    vis[R.first][R.second] = true;

    while(!q.empty())
    {
        int d = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if(mat[x][y] == 'L')
        {
            cout << d-1 << "\n";
            break;
        }

        if(!vis[x][y+1] && y+1 < MAX)
        {
            vis[x][y+1] = true;
            q.push({d+1,{x,y+1}});
        }
        if(!vis[x+1][y] && x+1 < MAX)
        {
            vis[x+1][y] = true;
            q.push({d+1,{x+1,y}});
        }
        if(!vis[x][y-1] && y-1 >= 0)
        {
            vis[x][y-1] = true;
            q.push({d+1,{x,y-1}});
        }
        if(!vis[x-1][y] && x-1 >= 0)
        {
            vis[x-1][y] = true;
            q.push({d+1,{x-1,y}});
        }
    }
}