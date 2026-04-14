#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    char mat[3][3];
    int r;
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            cin >> mat[i][j];
            if(mat[i][j] == '?')
                r = i;
        }
    }

    map<char,bool> mp;
    mp['A'] = mp['B'] = mp['C'] = false;
    for(int j = 0; j < 3; ++j)
    {
        if(mat[r][j] != '?')
            mp[mat[r][j]] = true;
    }

    for(auto el: mp)
    {
        if(!el.second)
            cout << el.first << "\n";
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
