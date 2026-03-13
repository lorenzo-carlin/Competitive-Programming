#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n; cin >> n;
    long long int a[n];
    long long int move = 0;
    cin >> a[0];
    for(int i = 1; i < n; ++i)
    {
        cin >> a[i];
        if(a[i] < a[i-1])
        {
            move += (a[i-1] - a[i]);
            a[i] = a[i-1];
        }
    }
    cout << move;
    return 0;
}