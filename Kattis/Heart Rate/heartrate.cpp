#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    while(n--)
    {
        double b, p; cin >> b >> p;

        double t = p / (b - 1);
        double abpmmn = 60 / t;

        double bpm = 60 * b / p;

        double abpmmx = 2*bpm - abpmmn;

        cout << fixed << setprecision(4) << floor(abpmmn*10000)/10000 << " " << floor(bpm*10000)/10000 << " " << floor(abpmmx*10000)/10000 << "\n";
    }
}