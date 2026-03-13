#include <bits/stdc++.h>
using namespace std;

int main()
{
    double c;
    cin >> c;
    c = min(c, 1.0);
    double ans = (c*c)/4;
    cout << fixed << setprecision(10) << ans;
    return 0;
}
