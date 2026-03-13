#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    if(n == 1)
    {
        cout << "1 ";
    } else if(n <= 3)
    {
        cout << "NO SOLUTION";
    } else if(n % 2 == 0)
    {
        int pm = n / 2;
        for(int i = 0; i < n/2; ++i)
        {
            cout << (pm-i) << " ";
            cout << (n-i) << " ";
        }
    } else if(n % 2 == 1)
    {
        int pm = n / 2;
        cout << (pm+1) << " ";
        for(int i = 0; i < n/2; ++i)
        {
            cout << (n-i) << " ";
            cout << (pm-i) << " ";
        }
    }
    return 0;
}