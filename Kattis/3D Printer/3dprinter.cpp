#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int c = 1, p = 1, g = 1;
    while(p < n)
    {
        p = p + c;
        c = c * 2;
        g++;
    }
    cout << g;
    return 0;
}
