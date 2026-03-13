#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int g, t, n; cin >> g >> t >> n;
    int w = g - t;
    w = w * 90 / 100;
    for(int i = 0; i < n; ++i)
    {
        int a; cin >> a;
        w -= a;
    }
    cout << w << "\n";
}