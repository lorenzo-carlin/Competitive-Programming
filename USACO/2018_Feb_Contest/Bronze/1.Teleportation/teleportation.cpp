#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    int a, b, c, d; cin >> a >> b >> c >> d;
    int maxx = max(c, d), minn = min(c, d);
    int mx = max(a, b), mn = min(a, b);

    int dist = mx - mn;
    dist = min(dist, abs(mn - minn) + abs(mx - maxx));
    cout << dist << "\n";

}