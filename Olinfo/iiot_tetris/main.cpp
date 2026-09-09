#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    int sol[n][m];

    if(n*m % 4)
    {
        cout << "-1\n";
        return 0;
    }

    int ind = 0;
    if(n % 4 == 0)
    {
        for(int i = 0; i < n/4; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                sol[4*i][j] = sol[4*i+1][j] = sol[4*i+2][j] = sol[4*i+3][j] = ind;
                ind++;
            }
        }
    } else if(m % 4 == 0)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m/4; ++j)
            {
                sol[i][4*j] = sol[i][4*j+1] = sol[i][4*j+2] = sol[i][4*j+3] = ind;
                ind++;
            }
        }
    } else
    {
        for(int i = 0; i < n/2; ++i)
        {
            for(int j = 0; j < m/2; ++j)
            {
                sol[2*i][2*j] = sol[2*i+1][2*j] = sol[2*i][2*j+1] = sol[2*i+1][2*j+1] = ind;
                ind++;
            }
        }
    }

    cout << ind << "\n";
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cout << sol[i][j] << " ";
        }
        cout << "\n";
    }
}