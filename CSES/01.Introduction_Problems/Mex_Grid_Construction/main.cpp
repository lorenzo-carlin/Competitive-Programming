#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int mat[n][n];
    set<int> s;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            s.clear();
            for(int k = 0; k < i; k++) s.insert(mat[k][j]);
            for(int k = 0; k < j; k++) s.insert(mat[i][k]);
            int t = 0;
            for(int k = 0; k < 200; k++)
            {
                if(!s.count(k))
                {
                    t = k;
                    break;
                }
            }
            mat[i][j] = t;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}
