#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, e; cin >> n >> m >> e;
    int mx = 0;
    for(; m <= n; ++m)
    {
        mx = max(mx, e % m);
    }
    cout << mx << "\n";
}