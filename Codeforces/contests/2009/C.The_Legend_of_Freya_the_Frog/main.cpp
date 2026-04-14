#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int x, y, k; cin >> x >> y >> k;
    int move_x = (x+k-1)/k, move_y = (y+k-1)/k;
    int ans = 2*max(move_x, move_y);
    if(move_y < move_x) ans--;
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
