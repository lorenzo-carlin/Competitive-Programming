#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        bool cond = false;

        char mat[3][3];
        for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                cin >> mat[i][j];
            }
        }

        for(int i = 0; i < 3; ++i)
        {
            if(mat[i][0] == mat[i][1] && mat[i][1] == mat[i][2] && mat[i][0] != '.')
            {
                cout << mat[i][1] << "\n";
                cond = true;
                break;
            }
        }

        if(cond) continue;

        for(int j = 0; j < 3; ++j)
        {
            if(mat[0][j] == mat[1][j] && mat[1][j] == mat[2][j] && mat[0][j] != '.')
            {
                cout << mat[0][j] << "\n";
                cond = true;
                break;
            }
        }

        if(cond) continue;

        if(mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2] && mat[0][0] != '.')
        {
            cout << mat[0][0] << "\n";
            cond = true;
        }

        if(cond) continue;

        if(mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0] && mat[0][2] != '.')
        {
            cout << mat[0][2] << "\n";
            cond = true;
        }

        if(cond) continue;

        cout << "DRAW\n";
    }
}