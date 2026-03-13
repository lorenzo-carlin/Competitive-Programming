#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int c;

    if(n % 2 == 0)
    {
        c = (n*n)/2;
    } else
    {
        c = ((n*n)/2)+1;
    }

    if(c % 2 == 0)
    {
        cout << "second\n";
    } else
    {
        cout << "first\n";
    }
}