#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c; cin >> r >> c;
    char mat[r][c];
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            cin >> mat[i][j];
        }
    }

    vector<int> v(5, 0);
    for(int i = 0; i < r-1; ++i)
    {
        for(int j = 0; j < c-1; ++j)
        {
            int parked = 0, free = 0;
            if(mat[i][j] == '.') free++;
            if(mat[i+1][j] == '.') free++;
            if(mat[i][j+1] == '.') free++;
            if(mat[i+1][j+1] == '.') free++;
            if(mat[i][j] == 'X') parked++;
            if(mat[i+1][j] == 'X') parked++;
            if(mat[i][j+1] == 'X') parked++;
            if(mat[i+1][j+1] == 'X') parked++;

            if(free + parked == 4) v[parked]++;
        }
    }

    for(int i = 0; i < 5; ++i)
    {
        cout << v[i] << "\n";
    }
}