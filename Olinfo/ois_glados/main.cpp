#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c, x, y; cin >> r >> c >> x >> y;
    vector<vector<char>> mat(r, vector<char> (c));
    vector<vector<bool>> ok(r, vector<bool> (c, false));
    vector<vector<bool>> vis(r, vector<bool> (c, false));
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            char car; cin >> car;
            mat[i][j] = car;
        }
    }

    auto dfs = [&] (auto dfs, int xx, int yy) -> void
    {
        if(xx < 0 || xx >= r || yy < 0 || yy >= c) return;
        if(ok[xx][yy]) return;

        ok[xx][yy] = true;

        if(mat[xx][yy] != '#') return;

        dfs(dfs, xx+1, yy);
        dfs(dfs, xx+1, yy+1);
        dfs(dfs, xx+1, yy-1);
        dfs(dfs, xx, yy+1);
        dfs(dfs, xx, yy-1);
        dfs(dfs, xx-1, yy);
        dfs(dfs, xx-1, yy+1);
        dfs(dfs, xx-1, yy-1);
    };

    dfs(dfs, x, y+1);

    queue<pair<int,int>> q;
    vis[x][y] = true;
    if(mat[x-1][y] == '.') q.push({x-1, y});
    else if(mat[x][y-1] == '.') q.push({x, y-1});
    else if(mat[x+1][y] == '.') q.push({x+1, y});

    auto check = [&] (int xx, int yy) -> bool
    {
        if(xx < 0 || xx >= r || yy < 0 || yy >= c) return false;
        if(mat[xx][yy] == '#' || vis[xx][yy] || !ok[xx][yy]) return false;
        return true;
    };

    int glue = 0;
    bool finish = false;

    while(!q.empty())
    {
        auto t = q.front();
        q.pop();

        int xx = t.first;
        int yy = t.second;
        if(mat[xx][yy] == '@')
        {
            glue++;
            continue;
        }
        if(mat[xx][yy] == 'O')
        {
            finish = true;
        }

        if(check(xx+1, yy))
        {
            vis[xx+1][yy] = true;
            q.push({xx+1, yy});
        }
        if(check(xx-1, yy))
        {
            vis[xx-1][yy] = true;
            q.push({xx-1, yy});
        }
        if(check(xx, yy+1))
        {
            vis[xx][yy+1] = true;
            q.push({xx, yy+1});
        }
        if(check(xx, yy-1))
        {
            vis[xx][yy-1] = true;
            q.push({xx, yy-1});
        }
    }

    if(finish) cout << "free\n";
    else if(glue) cout << "stuck\n";
    else cout << "cycling\n";
}
