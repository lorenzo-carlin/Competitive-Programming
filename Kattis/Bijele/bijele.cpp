#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v[6] = {1, 1, 2, 2, 2, 8};
    int in[6];
    for(int i = 0; i < 6; i++)
    {
        cin >> in[i];
    }
    for(int i = 0; i < 6; i++)
    {
        cout << v[i] - in[i] << " ";
    }
    return 0;
}