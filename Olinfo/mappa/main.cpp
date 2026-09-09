#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    bool mat[n][n];
    bool vis[n][n];
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            char c; cin >> c;
            if(c == '*') mat[i][j] = true;
            if(c == '+') mat[i][j] = false;
            vis[i][j] = false;
        }
    }
    
    queue<pair<int,pair<int,int>>> q;
    q.push({0, {0, 0}});
    while(!q.empty())
    {
        int d = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if(x == n-1 && y == n-1)
        {
            cout << d+1 << "\n";
            return 0;
        }
        
        if(vis[x][y]) continue;
        vis[x][y] = true;
        
        if(y+1 < n && mat[x][y+1]) q.push({d+1, {x, y+1}});
        if(x+1 < n && y+1 < n && mat[x+1][y+1]) q.push({d+1, {x+1, y+1}});
        if(x+1 < n && mat[x+1][y]) q.push({d+1, {x+1, y}});
        if(x+1 < n && y-1 >= 0 && mat[x+1][y-1]) q.push({d+1, {x+1, y-1}});
        if(y-1 >= 0 && mat[x][y-1]) q.push({d+1, {x, y-1}});
        if(x-1 >= 0 && y-1 >= 0 && mat[x-1][y-1]) q.push({d+1, {x-1, y-1}});
        if(x-1 >= 0 && mat[x-1][y]) q.push({d+1, {x-1, y}});
        if(x-1 >= 0 && y+1 < n && mat[x-1][y+1]) q.push({d+1, {x-1, y+1}});
    }
    
}