#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    if(n % 2)
    {
        cout << "Either\n";
    } else if(n % 4 == 0)
    {
        cout << "Even\n";
    } else
    {
        cout << "Odd\n";
    }
}