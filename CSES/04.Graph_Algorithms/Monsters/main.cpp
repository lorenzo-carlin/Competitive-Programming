#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define f first
#define s second

enum { U, D, L, R };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c; cin >> r >> c;
    pair<int,int> A;
    vector<pair<int,int>> M;
    char mat[r][c];
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            cin >> mat[i][j];
            if(mat[i][j] == 'A') A = {i, j};
            if(mat[i][j] == 'M') M.push_back({i, j});
        }
    }

    // distanza minima da A a tutti i punti del labirinto
    vector<vector<int>> father(r, vector<int> (c, -2));
    vector<vector<int>> dist(r, vector<int> (c, 1e9));
    queue<pair<int,pair<pair<int,int>,int>>> q;
    q.push({-0, {{A.f, A.s}, -1}});
    while(!q.empty())
    {
        int d = -q.front().first;
        pair<int,int> att = q.front().second.first;
        int last = q.front().second.second;
        q.pop();

        if(d >= dist[att.f][att.s]) continue;
        dist[att.f][att.s] = d;
        father[att.f][att.s] = last;

        // vado in basso
        if(att.f+1 < r && mat[att.f+1][att.s] != '#') q.push({-(d+1), {{att.f+1, att.s}, D}});

        // vado in alto
        if(att.f-1 >= 0 && mat[att.f-1][att.s] != '#') q.push({-(d+1), {{att.f-1, att.s}, U}});

        // vado a destra
        if(att.s+1 < c && mat[att.f][att.s+1] != '#') q.push({-(d+1), {{att.f, att.s+1}, R}});

        // vado a sinistra
        if(att.s-1 >= 0 && mat[att.f][att.s-1] != '#') q.push({-(d+1), {{att.f, att.s-1}, L}});
    }

    // distanza minima da ciascun mostro a tutti i punti del labirinto
    vector<vector<int>> dist_m(r, vector<int> (c, 1e9));
    queue<pair<int,pair<int,int>>> q_m;
    for(auto el: M)
        q_m.push({-0, {el.f, el.s}});

    while(!q_m.empty())
    {
        int d = -q_m.front().first;
        pair<int,int> att = q_m.front().second;
        q_m.pop();

        if(d >= dist_m[att.f][att.s]) continue;
        dist_m[att.f][att.s] = d;

        // vado in basso
        if(att.f+1 < r && mat[att.f+1][att.s] != '#') q_m.push({-(d+1), {att.f+1, att.s}});

        // vado in alto
        if(att.f-1 >= 0 && mat[att.f-1][att.s] != '#') q_m.push({-(d+1), {att.f-1, att.s}});

        // vado a destra
        if(att.s+1 < c && mat[att.f][att.s+1] != '#') q_m.push({-(d+1), {att.f, att.s+1}});

        // vado a sinistra
        if(att.s-1 >= 0 && mat[att.f][att.s-1] != '#') q_m.push({-(d+1), {att.f, att.s-1}});
    }

    bool sol = false;
    pair<int,int> ans;

    for(int i = 0; i < c; ++i)
    {
        if(mat[0][i] == '#') continue;
        if(dist_m[0][i] > dist[0][i])
        {
            sol = true;
            ans = {0, i};
        }
    }

    for(int i = 0; i < c; ++i)
    {
        if(mat[r-1][i] == '#') continue;
        if(dist_m[r-1][i] > dist[r-1][i])
        {
            sol = true;
            ans = {r-1, i};
        }
    }

    for(int i = 0; i < r; ++i)
    {
        if(mat[i][0] == '#') continue;
        if(dist_m[i][0] > dist[i][0])
        {
            sol = true;
            ans = {i, 0};
        }
    }

    for(int i = 0; i < r; ++i)
    {
        if(mat[i][c-1] == '#') continue;
        if(dist_m[i][c-1] > dist[i][c-1])
        {
            sol = true;
            ans = {i, c-1};
        }
    }

    if(!sol) cout << "NO\n";
    else
    {
        string st;
        while(father[ans.f][ans.s] != -1)
        {
            if(father[ans.f][ans.s] == U)
            {
                st += 'U';
                ans = {ans.f+1, ans.s};
            } else if(father[ans.f][ans.s] == D)
            {
                st += 'D';
                ans = {ans.f-1, ans.s};
            } else if(father[ans.f][ans.s] == L)
            {
                st += 'L';
                ans = {ans.f, ans.s+1};
            } else if(father[ans.f][ans.s] == R)
            {
                st += 'R';
                ans = {ans.f, ans.s-1};
            }
        }

        reverse(begin(st), end(st));

        cout << "YES\n" << st.size() << "\n" << st << "\n";
    }
}