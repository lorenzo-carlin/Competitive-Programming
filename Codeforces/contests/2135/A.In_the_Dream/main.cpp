#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int A, B, C, D; cin >> A >> B >> C >> D;
    int a = A, b = B, c = C, d = D;

    bool possible = true;
    if(a < b) swap(a, b);
    if(a > 2*(b+1)) possible = false;
    c -= A;
    d -= B;
    if(c < d) swap(c, d);
    if(c > 2*(d+1)) possible = false;

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
