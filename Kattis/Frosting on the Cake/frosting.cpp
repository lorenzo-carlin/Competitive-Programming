#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int vA[n];
    int vB[n];
    long long int l[3];
    long long int h[3];
    for(int i = 0; i < n; i++)
    {
        cin >> vA[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> vB[i];
    }
    for(int i = 0; i < 3; i++)
    {
        l[i] = 0;
        h[i] = 0;
    }
    for(int i = 0; i < n; i++)
    {
        if(i % 3 == 0)
        {
            l[0] += vA[i];
            h[0] += vB[i];
        } else if(i % 3 == 1)
        {
            l[1] += vA[i];
            h[1] += vB[i];
        } else if(i % 3 == 2)
        {
            l[2] += vA[i];
            h[2] += vB[i];
        }
    }
    long long int col0 = (l[0] * h[1]) + (l[1] * h[0]) + (l[2] * h[2]);
    long long int col1 = (l[0] * h[2]) + (l[1] * h[1]) + (l[2] * h[0]);
    long long int col2 = (l[0] * h[0]) + (l[1] * h[2]) + (l[2] * h[1]);
    cout << col0 << " " << col1 << " " << col2;
    return 0;
}
