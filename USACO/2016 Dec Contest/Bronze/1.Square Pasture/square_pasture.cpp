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
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);

    rectangle a; cin >> a.l >> a.d >> a.r >> a.u;
    rectangle b; cin >> b.l >> b.d >> b.r >> b.u;

    int w = max(a.r, b.r) - min(a.l, b.l);
    int h = max(a.u, b.u) - min(a.d, b.d);
    int sol = max(w,h)*max(w,h);

    cout << sol << "\n";
}