#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    if(n <= 360) cout << 0 << "\n";
    else if(n <= 390) cout << n-360 << "\n";
    else if(n <= 570) cout << 30 << "\n";
    else if(n <= 585) cout << n-570+30 << "\n";
    else if(n <= 645) cout << 45 << "\n";
    else cout << n-600 << "\n";
}
