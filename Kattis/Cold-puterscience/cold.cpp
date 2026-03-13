#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, c = 0;
    cin >> n;
    int t[n];
    for(int i = 0; i < n; i++)
    {
        cin >> t[i];
        if(t[i] < 0)
        {
            c++;
        }
    }
    cout << c;
    return 0;
}
