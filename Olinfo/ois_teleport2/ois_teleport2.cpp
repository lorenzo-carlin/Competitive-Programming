#include <bits/stdc++.h>
using namespace std;

double dist(double xa, double ya, double xb, double yb)
{
    return sqrt((double)(xa-xb)*(xa-xb)+(double)(ya-yb)*(ya-yb));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--)
    {
        double xa, ya, xb, yb, xc, yc, r; cin >> xa >> ya >> xb >> yb >> xc >> yc >> r;
        double sol = min(dist(xa, ya, xb, yb), max(dist(xa, ya, xc, yc)-r, 0.0)+max(dist(xb, yb, xc, yc)-r, 0.0));
        sol = floor(sol * 1000000) / 1000000;
        cout << fixed << sol << "\n";
    }
}