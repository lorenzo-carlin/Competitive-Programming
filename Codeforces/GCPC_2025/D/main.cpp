#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    int mn_x = 1e9, mx_x = 1, mn_y = 1e9, mx_y = 1;
    for(int i = 0, a, b; i < n; i++)
    {
        cin >> a >> b;
        mn_x = min(mn_x, a);
        mx_x = max(mx_x, a);
        mn_y = min(mn_y, b);
        mx_y = max(mx_y, b);
    }

    cout << 4 << "\n";
    cout << mn_x << " " << mn_y << "\n";
    cout << mx_x << " " << mn_y << "\n";
    cout << mx_x << " " << mx_y << "\n";
    cout << mn_x << " " << mx_y << "\n";
}
