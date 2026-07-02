#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int GCD(int a, int b) {
    if(b == 0) {
        return a;
    } else {
        return GCD(b, a%b);
    }
}

void solve()
{
    int n, m, a, b; cin >> n >> m >> a >> b;
    if(GCD(n,a) == 1 && GCD(m,b) == 1 && GCD(n,m) <= 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
