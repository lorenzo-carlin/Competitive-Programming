#include <bits/stdc++.h>
using namespace std;

void func(int m[4][4], int v);

int main()
{
    int m[4][4];
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cin >> m[i][j];
        }
    }
    int v;
    cin >> v;
    func(m, v);
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}

void func(int m[4][4], int v)
{

    if(v == 0)
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 1; j < 4; j++)
            {
                if(m[i][j-1] == 0)
                {
                    m[i][j-1] = m[i][j];
                    m[i][j] = 0;
                }
            }
            for(int j = 1; j < 4; j++)
            {
                if(m[i][j-1] == 0)
                {
                    m[i][j-1] = m[i][j];
                    m[i][j] = 0;
                }
            }
            for(int j = 1; j < 4; j++)
            {
                if(m[i][j-1] == 0)
                {
                    m[i][j-1] = m[i][j];
                    m[i][j] = 0;
                }
            }
            for(int j = 1; j < 4; j++)
            {
                if(m[i][j] == m[i][j-1])
                {
                    m[i][j-1] = m[i][j]*2;
                    m[i][j] = 0;
                }
            }
            for(int j = 1; j < 4; j++)
            {
                if(m[i][j-1] == 0)
                {
                    m[i][j-1] = m[i][j];
                    m[i][j] = 0;
                }
            }
        }
    } else if(v == 1)
    {
        for(int j = 0; j < 4; j++)
        {
            for(int i = 1; i < 4; i++)
            {
                if(m[i-1][j] == 0)
                {
                    m[i-1][j] = m[i][j];
                    m[i][j] = 0;
                }
            }
            for(int i = 1; i < 4; i++)
            {
                if(m[i-1][j] == 0)
                {
                    m[i-1][j] = m[i][j];
                    m[i][j] = 0;
                }
            }
            for(int i = 1; i < 4; i++)
            {
                if(m[i-1][j] == 0)
                {
                    m[i-1][j] = m[i][j];
                    m[i][j] = 0;
                }
            }
            for(int i = 1; i < 4; i++)
            {
                if(m[i-1][j] == m[i][j])
                {
                    m[i-1][j] = m[i][j]*2;
                    m[i][j] = 0;
                }
            }
            for(int i = 1; i < 4; i++)
            {
                if(m[i-1][j] == 0)
                {
                    m[i-1][j] = m[i][j];
                    m[i][j] = 0;
                }
            }
        }
    } else if(v == 2)
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 2; j >= 0; j--)
            {
                if(m[i][j+1] == 0)
                {
                    m[i][j+1] = m[i][j];
                    m[i][j] = 0;
                }
            }
            for(int j = 2; j >= 0; j--)
            {
                if(m[i][j+1] == 0)
                {
                    m[i][j+1] = m[i][j];
                    m[i][j] = 0;
                }
            }
            for(int j = 2; j >= 0; j--)
            {
                if(m[i][j+1] == 0)
                {
                    m[i][j+1] = m[i][j];
                    m[i][j] = 0;
                }
            }
            for(int j = 2; j >= 0; j--)
            {
                if(m[i][j+1] == m[i][j])
                {
                    m[i][j+1] = m[i][j]*2;
                    m[i][j] = 0;
                }
            }
            for(int j = 2; j >= 0; j--)
            {
                if(m[i][j+1] == 0)
                {
                    m[i][j+1] = m[i][j];
                    m[i][j] = 0;
                }
            }
        }
    } else if(v == 3)
    {
        for(int j = 0; j < 4; j++)
        {
            for(int i = 2; i >= 0; i--)
            {
                if(m[i+1][j] == 0)
                {
                    m[i+1][j] = m[i][j];
                    m[i][j] = 0;
                }
            }
            for(int i = 2; i >= 0; i--)
            {
                if(m[i+1][j] == 0)
                {
                    m[i+1][j] = m[i][j];
                    m[i][j] = 0;
                }
            }
            for(int i = 2; i >= 0; i--)
            {
                if(m[i+1][j] == 0)
                {
                    m[i+1][j] = m[i][j];
                    m[i][j] = 0;
                }
            }
            for(int i = 2; i >= 0; i--)
            {
                if(m[i+1][j] == m[i][j])
                {
                    m[i+1][j] = m[i][j]*2;
                    m[i][j] = 0;
                }
            }
            for(int i = 2; i >= 0; i--)
            {
                if(m[i+1][j] == 0)
                {
                    m[i+1][j] = m[i][j];
                    m[i][j] = 0;
                }
            }
        }
    }
}
