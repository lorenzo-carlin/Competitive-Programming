#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int A; cin >> A;
    int m[A][A];
    for(int i = 0; i < A; ++i)
    {
        for(int j = 0; j < i+1; ++j)
        {
            cin >> m[i][j];
        }
    }
    for(int i = A-1; i >= 0; --i)
    {
        for(int j = 0; j < i; ++j)
        {
            m[i-1][j] += max(m[i][j], m[i][j+1]);
        }
    }
    int n = m[0][0];
    cout << n;
    return 0;
}