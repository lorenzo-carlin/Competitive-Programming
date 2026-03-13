#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int dist[n][n];
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            dist[i][j] = 1e9;
        }
    }

    auto control = [&] (int x, int y) -> bool
    {
        if(x < 0 || x >= n || y < 0 || y >= n) return false;
        return true;
    };

    queue<pair<int,int>> q;
    q.push({0,0});
    dist[0][0] = 0;
    while(!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        
        int d = dist[xx][yy];

        if(control(xx-1,yy+2) && dist[xx-1][yy+2] > d+1)
        {
            dist[xx-1][yy+2] = d+1;
            q.push({xx-1,yy+2});
        }
        if(control(xx+1,yy+2) && dist[xx+1][yy+2] > d+1)
        {
            dist[xx+1][yy+2] = d+1;
            q.push({xx+1,yy+2});
        }
        if(control(xx+2,yy+1) && dist[xx+2][yy+1] > d+1)
        {
            dist[xx+2][yy+1] = d+1;
            q.push({xx+2,yy+1});
        }
        if(control(xx+2,yy-1) && dist[xx+2][yy-1] > d+1)
        {
            dist[xx+2][yy-1] = d+1;
            q.push({xx+2,yy-1});
        }
        if(control(xx-2,yy+1) && dist[xx-2][yy+1] > d+1)
        {
            dist[xx-2][yy+1] = d+1;
            q.push({xx-2,yy+1});
        }
        if(control(xx-2,yy-1) && dist[xx-2][yy-1] > d+1)
        {
            dist[xx-2][yy-1] = d+1;
            q.push({xx-2,yy-1});
        }
        if(control(xx-1,yy-2) && dist[xx-1][yy-2] > d+1)
        {
            dist[xx-1][yy-2] = d+1;
            q.push({xx-1,yy-2});
        }
        if(control(xx+1,yy-2) && dist[xx+1][yy-2] > d+1)
        {
            dist[xx+1][yy-2] = d+1;
            q.push({xx+1,yy-2});
        }
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
