#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;

    int curr = 1, sol = 0, mn = 0;
    for(int i = 0; i < n; ++i)
    {
        int a, b; cin >> a >> b; b++;
        sol -= (a - curr);
        mn = min(mn, sol);
        sol += (b - a);
        curr = b;
    }
    sol -= (m - curr + 1);
    mn = min(mn, sol);

    cout << abs(mn-1) << "\n";
}