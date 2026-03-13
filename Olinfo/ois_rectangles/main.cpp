#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    array<int,3> a;
    cin >> a[0] >> a[1] >> a[2];

    sort(begin(a), end(a));
    if(a[0] == a[1] && a[1] == a[2]) cout << 1 << "\n";
    else if(a[0] == a[1] || a[1] == a[2]) cout << 3 << "\n";
    else cout << 6 << "\n";
}
