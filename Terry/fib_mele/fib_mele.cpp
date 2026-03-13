#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t; cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        int tot = a * b;
        cout << "Case #" << i << ": ";
        if(c < tot)
        {
            cout << c << "\n";
        } else
        {
            cout << tot << "\n";
        }
    }
}