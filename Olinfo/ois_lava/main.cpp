#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c; cin >> r >> c;
    vector<vector<bool>> pos(r, vector<bool> (c, false));
    vector<vector<int>> dist(r, vector<int> (c, 1e9));

    char tmp;
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            cin >> tmp;
            if(tmp == '.') pos[i][j] = true;
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
        if(x >= 0 && x < r && y >= 0 && y < c && pos[x][y] && d < dist[x][y])
        {
            dist[x][y] = d;
            q.push({d+1, {x+1, y}});
            q.push({d+1, {x+1, y-1}});
            q.push({d+1, {x, y-1}});
            q.push({d+1, {x-1, y-1}});
            q.push({d+1, {x-1, y}});
            q.push({d+1, {x-1, y+1}});
            q.push({d+1, {x, y+1}});
            q.push({d+1, {x+1, y+1}});
            q.push({d+1, {x, y+2}});
            q.push({d+1, {x+2, y}});
            q.push({d+1, {x, y-2}});
            q.push({d+1, {x-2, y}});
        }
    }
    cout << dist[r-1][c-1] << "\n";
}