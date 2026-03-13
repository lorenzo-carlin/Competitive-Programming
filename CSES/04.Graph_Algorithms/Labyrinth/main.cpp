#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct co { int x, y; };
enum { U, D, L, R };

int main()
{
    // freopen("input.txt", "r", stdin);

    cerr << "c0\n";

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c; cin >> r >> c;
    cerr << r << " " << c << "\n";
    // cerr << "c0a\n";
    vector<vector<char>> mat(r, vector<char>(c));
    // char mat[r][c];
    // cerr << "c0b\n";
    vector<vector<bool>> vis(r, vector<bool> (c));
    // bool vis[r][c];
    // cerr << "c0c\n";
    vector<vector<int>> move(r, vector<int> (c));
    // bool move[r][c];
    // cerr << "c0d\n";
    vector<vector<int>> dist(r, vector<int> (c));
    // bool dist[r][c];
    // char mat[r][c];
    // bool vis[r][c];

    // cerr << "c1\n";
    co st, fn;
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            cin >> mat[i][j];
            if(mat[i][j] == 'A') st = {i, j};
            if(mat[i][j] == 'B') fn = {i, j};
            dist[i][j] = 1e9;
            move[i][j] = 0;
            vis[i][j] = false;
        }
    }

    // cerr << "c2\n";

    // -dist, coordinate della cella attuale, ultima mossa fatta
    queue<pair<int,pair<co,int>>> q;
    q.push({-0, {st, 0}});

    while(!q.empty())
    {
        int d = -q.front().first;
        co att = q.front().second.first;
        int m = q.front().second.second;
        q.pop();
        
        // cerr << "c3\n";

        // cout << att.x << " " << att.y << " ";

        if((d >= dist[att.x][att.y]) || (mat[att.x][att.y] == '#') || (vis[att.x][att.y]))
        {
            // cout << "x\n";
            continue;
        }
        // cout << "v\n";
        dist[att.x][att.y] = d;
        vis[att.x][att.y] = true;
        move[att.x][att.y] = m;

        // cout << att.x << " " << att.y << "\n";

        // if(att.x == fn.x && att.y == fn.y) break;

        // cerr << "c4\n";
        // vado sopra
        if(att.x-1 >= 0) q.push({-(d+1), {{att.x-1, att.y}, U}});
        // vado sotto
        if(att.x+1 < r) q.push({-(d+1), {{att.x+1, att.y}, D}});
        // vai a sinistra
        if(att.y-1 >= 0) q.push({-(d+1), {{att.x, att.y-1}, L}});
        // vai a destra
        if(att.y+1 < c) q.push({-(d+1), {{att.x, att.y+1}, R}});

        // cerr << "c5\n";
    }

    if(dist[fn.x][fn.y] == 1e9) cout << "NO\n";
    else
    {
        // cerr << "c6\n";

        cout << "YES\n";
        cout << dist[fn.x][fn.y] << "\n";
        string s;
        co tmp = fn;
        while(tmp.x != st.x || tmp.y != st.y)
        {
            s += to_string(move[tmp.x][tmp.y]);

            if(move[tmp.x][tmp.y] == U) tmp = {tmp.x+1, tmp.y};
            else if(move[tmp.x][tmp.y] == D) tmp = {tmp.x-1, tmp.y};
            else if(move[tmp.x][tmp.y] == L) tmp = {tmp.x, tmp.y+1};
            else if(move[tmp.x][tmp.y] == R) tmp = {tmp.x, tmp.y-1};
        }
        reverse(begin(s), end(s));
        for(auto &i: s)
        {
            if(i == '0') i = 'U';
            if(i == '1') i = 'D';
            if(i == '2') i = 'L';
            if(i == '3') i = 'R';
        }
        cout << s << "\n";
    }
    

}