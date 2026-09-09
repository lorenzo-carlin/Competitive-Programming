#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    char mat[n][m];
    int rig[n][m]; rig[0][0] = 0;
    int col[n][m]; col[0][0] = 0;
    int dia[n][m]; dia[0][0] = 0;
    int mxr = 0, mxc = 0, mxd = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            char a; cin >> a;
            mat[i][j] = a;
            if(i == 0 && j == 0)
                continue;
            if(i == 0)
            {
                col[i][j] = 0;
                dia[i][j] = 0;
            } else
            {
                if(mat[i][j] == mat[i-1][j])
                {
                    col[i][j] = col[i-1][j]+1;
                    if(col[i][j] > mxc)
                    {
                        mxc = col[i][j];
                    }
                } else
                {
                    col[i][j] = 0;
                }
            }
            if(j == 0)
            {
                rig[i][j] = 0;
                dia[i][j] = 0;
            } else
            {
                if(mat[i][j] == mat[i][j-1])
                {
                    rig[i][j] = rig[i][j-1]+1;
                    if(rig[i][j] > mxr)
                    {
                        mxr = rig[i][j];
                    }
                } else
                {
                    rig[i][j] = 0;
                }
            }
            if(i != 0 && j != 0)
            {
                if(mat[i][j] == mat[i-1][j-1])
                {
                    dia[i][j] = dia[i-1][j-1]+1;
                    if(dia[i][j] > mxd)
                    {
                        mxd = dia[i][j];
                    }
                } else
                {
                    dia[i][j] = 0;
                }
            }
        }
    }
    int dig[n][m]; dig[0][m-1] = 0;
    int mxd2 = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = m-1; j >= 0; --j)
        {
            if(i == 0 && j == m-1)
                continue;
            if(i == 0 || j == m-1)
            {
                dig[i][j] = 0;
            } else
            {
                if(mat[i][j] == mat[i-1][j+1])
                {
                    dig[i][j] = dig[i-1][j+1]+1;
                    if(dig[i][j] > mxd2)
                    {
                        mxd2 = dig[i][j];
                    }
                } else
                {
                    dig[i][j] = 0;
                }
            }
        }
    }
    /*
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cout << col[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "MXR: " << mxr << endl;
    cout << "MXC: " << mxc << endl;
    cout << "MXD: " << mxd << endl;
    cout << "MXD2: " << mxd2 << endl;*/
    int mx1 = max(mxr, mxc);
    int mx2 = max(mxd, mxd2);
    cout << max(mx1, mx2)+1;
}