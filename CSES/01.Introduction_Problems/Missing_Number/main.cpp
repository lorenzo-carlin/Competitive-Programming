#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int v[n];
    int m;
    for(int i = 0; i < n; ++i)
    {
        v[i] = 0;
    }
    for(int i = 0; i < n-1; ++i)
    {
        cin >> m;
        v[m-1]++;
    }
    for(int i = 0; i < n; ++i)
    {
        if(v[i] == 0)
        {
            cout << i+1;
            break;
        }
    }
}