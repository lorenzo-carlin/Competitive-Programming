#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double c; cin >> c;
    int l; cin >> l;

    double tot = 0.000000;
    for(int i = 0; i < l; ++i)
    {
        double a, b; cin >> a >> b;
        tot += (a*b*c);
    }

    cout.precision(7);
    cout << tot << "\n";
}