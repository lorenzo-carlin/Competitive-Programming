#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m, k; cin >> n >> m >> k;
    string p; cin >> p;
    bool vis[n][m] = {};

    int x = 0, y = 0;
    vis[0][0] = true;

    vector<int> idx;
    idx.push_back(0);
    for(int i = 0; i < p.size(); i++)
    {
        if(p[i] == 'R')
            y++;
        else if(p[i] == 'L')
            y--;
        else if(p[i] == 'U')
            x--;
        else if(p[i] == 'D')
            x++;
        if(!vis[x][y])
            idx.push_back(i+1);
        vis[x][y] = true;
    }

    int rem = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!vis[i][j])
                rem++;

    if(rem >= k) cout << p.size() << "\n";
    else
    {
        k -= rem;
        k--;
        while(k--) idx.pop_back();
        cout << idx.back()-1 << "\n";
    }
}
