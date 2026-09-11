#include <bits/stdc++.h>
using namespace std;

struct rectangle
{
    int l;
    int d;
    int r;
    int u;
};

int main()
{
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    rectangle a; cin >> a.l >> a.d >> a.r >> a.u;
    int area = (a.r-a.l)*(a.u-a.d);

    rectangle b; cin >> b.l >> b.d >> b.r >> b.u;
    
    if(b.u >= a.u && b.d <= a.d)
    {
        int dif = max(0, min(b.r, a.r) - max(b.l, a.l));
        area -= dif * (a.u - a.d);
    } else if(b.l <= a.l && b.r >= a.r)
    {
        int dif = max(0, min(b.u, a.u) - max(b.d, a.d));
        area -= dif * (a.r - a.l);
    }

    cout << area << "\n";
}