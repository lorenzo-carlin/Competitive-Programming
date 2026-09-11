#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    int b1, b2; cin >> b1 >> b2;
    int s1, s2; cin >> s1 >> s2;
    int g1, g2; cin >> g1 >> g2;
    int p1, p2; cin >> p1 >> p2;

    int prom1 = 0, prom2 = 0, prom3 = 0;

    prom1 = (p2 - p1);
    g2 += prom1;

    prom2 = (g2 - g1);
    s2 += prom2;

    prom3 = (s2 - s1);
    b2 += prom3;

    cout << prom3 << "\n" << prom2 << "\n" << prom1 << "\n";
}