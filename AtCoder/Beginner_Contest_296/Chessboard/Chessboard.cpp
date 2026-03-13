#include <bits/stdc++.h>
using namespace std;

const int MAX = 8;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x, y;
    char mat[MAX][MAX];
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            cin >> mat[i][j];
            if(mat[i][j] == '*')
            {
                x = i;
                y = j;
            }
        }
    }
    x = 8 - x;
    y += 97;
    cout << char(y) << x << "\n";
}