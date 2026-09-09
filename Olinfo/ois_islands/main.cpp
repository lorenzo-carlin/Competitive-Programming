#include <bits/stdc++.h>
using namespace std;

int r, c;
const int MAX = 1000;
int mappa[MAX][MAX];
bool vis[MAX][MAX];

void dfs(int i, int j)
{
    if(i < 0 || j < 0 || i == r || j == c || (mappa[i][j] == 0) || vis[i][j])
    {
        return;
    }

    vis[i][j] = true;

    dfs(i-1, j);
    dfs(i, j-1);
    dfs(i+1, j);
    dfs(i, j+1);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> r >> c;

    // input della mappa
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            cin >> mappa[i][j];
        }
    }

    // ricerca delle isole "irregolari":
    // Caso 1: prima riga
    for(int j = 0; j < c; ++j)
    {
        if(mappa[0][j] == 1 && !vis[0][j])
        {
            dfs(0, j);
        }
    }

    // Caso 2: prima colonna
    for(int i = 0; i < r; ++i)
    {
        if(mappa[i][0] == 1 && !vis[i][0])
        {
            dfs(i, 0);
        }
    }

    // Caso 3: ultima riga
    for(int j = 0; j < c; ++j)
    {
        if(mappa[r-1][j] == 1 && !vis[r-1][j])
        {
            dfs(r-1, j);
        }
    }

    // Caso 4: ultima colonna
    for(int i = 0; i < r; ++i)
    {
        if(mappa[i][c-1] == 1 && !vis[i][c-1])
        {
            dfs(i, c-1);
        }
    }

    // ricerca delle isole "regolari":
    int ans = 0;
    for(int i = 1; i < r; ++i)
    {
        for(int j = 1; j < c; ++j)
        {
            if(mappa[i][j] == 1 && !vis[i][j])
            {
                dfs(i, j);
                ans++;
            }
        }
    }

    cout << ans;
}