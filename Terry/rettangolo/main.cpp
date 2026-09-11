#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for(int p = 1; p <= t; ++p)
    {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        int x, y;
        if(x1 == x2) x = x3;
        if(x1 == x3) x = x2;
        if(x2 == x3) x = x1;

        if(y1 == y2) y = y3;
        if(y1 == y3) y = y2;
        if(y2 == y3) y = y1;

        cout << "Case #" << p << ": " << x << " " << y << "\n";
    }
}