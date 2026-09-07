/*
 * Queens on a Chessboard
 * Solves the N-Queens problem by placing queens so that no two attack each other.
 */


#include <bits/stdc++.h>
using namespace std;

int n;
const int MAX = 1e3;
vector<bool> column;
vector<bool> diag1;
vector<bool> diag2;
int sol = 0;

void search(int y)
{
    if(y == n)
    {
        sol++;
        return;
    } else
    {
        for(int i = 0; i < n; ++i)
        {
            if(column[i] || diag1[i+y] || diag2[i-y+n-1]) continue;
            column[i] = diag1[i+y] = diag2[i-y+n-1] = true;
            search(y+1);
            column[i] = diag1[i+y] = diag2[i-y+n-1] = false;
        }
    }
}

int main()
{
    cin >> n;

    column.resize(n, false);
    diag1.resize(2*n-1, false);
    diag2.resize(2*n-1, false);
    
    search(0);
    cout << sol << "\n";
}
