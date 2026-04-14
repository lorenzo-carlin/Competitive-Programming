#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, a, b; cin >> n >> a >> b;

    bool possible = true;
    if(n & 1)
    {
        if(!(b & 1))
        {
            possible = false;
        } else if(!(a & 1) && a > b)
        {
            possible = false;
        }
    } else
    {
        if(b & 1)
        {
            possible = false;
        } else if((a & 1) && a > b)
        {
            possible = false;
        }
    }

    if(possible) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
