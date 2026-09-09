#include <bits/stdc++.h>
using namespace std;

int total(int X, int Y, int Z)
{
    int tot = 0;
    tot += X*40;
    Y = max(0, Y-5000);
    Z += Y;
    if(Z <= 10000) tot += 20*Z;
    else tot += (200000 + 60 * (Z - 10000));
    return tot;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x, y, z, w; cin >> x >> y >> z >> w;

    int mn = 1e9;
    int tmp = max(0, x-w);
    mn = min(mn, total(tmp, y, z));
    tmp = max(0, y-w);
    mn = min(mn, total(x, tmp, z));
    tmp = max(0, z-w);
    mn = min(mn, total(x, y, tmp));

    cout << mn << "\n";
}