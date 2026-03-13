#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll l, n; cin >> l >> n;
    ll tot = l + n + (n/2) + 2*(n/3) - (n/6);
    cout << tot << "\n";
}
