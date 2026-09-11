#include <bits/stdc++.h>
using namespace std;

struct rectangle
{
    int l;
    int d;
    int r;
    int u;
};

int intersection(rectangle a, rectangle b)
{
    if((a.d >= b.u || a.u <= b.d) || (a.l >= b.r || a.r <= b.l)) return 0;
    int w = min(a.r, b.r) - max(a.l, b.l);
    int h = min(a.u, b.u) - max(a.d, b.d);
    return w*h;
}

int main()
{
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int tot = 0;

    rectangle a; cin >> a.l >> a.d >> a.r >> a.u;
    tot += (a.r - a.l) * (a.u - a.d);

    rectangle b; cin >> b.l >> b.d >> b.r >> b.u;
    tot += (b.r - b.l) * (b.u - b.d);

    rectangle c; cin >> c.l >> c.d >> c.r >> c.u;
    tot -= intersection(a, c);
    tot -= intersection(b, c);

    cout << tot << "\n";
}